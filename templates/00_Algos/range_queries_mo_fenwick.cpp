/*
 * Range distinct-count templates: (1) Mo's algorithm  (2) Offline sweep + Fenwick (BIT)
 *
 * Problem: given array a[0..n-1] and q queries [l, r] (inclusive),
 *          print the number of distinct values in a[l..r] for each query.
 *
 * Input format (queries are 1-indexed in the input, converted to 0-indexed inside):
 *   n q
 *   a_1 ... a_n
 *   l r      (q lines)
 *
 * Both solvers are OFFLINE (they need all queries upfront).
 *
 * Quick comparison:
 *   Mo's      : O((n + q) * sqrt(n))  - general, only needs add()/remove() of an element.
 *   Fenwick   : O((n + q) * log n)    - faster, but needs the answer to be a sum of
 *                                       per-position contributions that depend only on r.
 */

#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------------------------------------ */
/* Shared helper: coordinate compression                               */
/* ------------------------------------------------------------------ */
// Maps arbitrary values (possibly huge / negative) to 0..m-1 so we can use
// plain arrays instead of hash maps. Returns m = number of distinct values.
int compress(vector<int>& a) {
  vector<int> vals = a;
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
  for (int& x : a) x = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
  return (int)vals.size();
}

/* ================================================================== */
/* PART 1: MO'S ALGORITHM                                              */
/* ================================================================== */
/*
 * Idea: keep ONE window [curL, curR] and its answer. To answer the next
 * query, slide the window's endpoints one step at a time, updating the
 * answer in O(1) per step. Sort queries so total pointer movement is small.
 *
 * State:
 *   cnt[v]   = occurrences of value v inside the window
 *   distinct = number of values with cnt > 0
 *
 * Complexity: O((n + q) * sqrt(n)) pointer moves, each O(1).
 *
 * To adapt Mo's to another problem, only change: the state, add(), remove(),
 * and what you store as the answer. The rest stays the same.
 *
 * a       : compressed array (values in [0, m))
 * m       : number of distinct values after compression
 * queries : {l, r} pairs, 0-indexed inclusive
 */
vector<int> solveMo(const vector<int>& a, int m, const vector<array<int, 2>>& queries) {
  int n = a.size(), q = queries.size();

  // Block size. n / sqrt(q) is the theoretically best choice;
  // plain sqrt(n) also works fine. max(1, ...) avoids division by zero.
  int B = max(1, (int)(n / sqrt((double)max(q, 1))));

  // Sort query indices by (block of l, then r).
  // Odd-even trick: in odd blocks r is sorted descending, so r sweeps
  // right on one block and back left on the next (saves ~2x pointer moves).
  vector<int> order(q);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&] (int x, int y) {
    int bx = queries[x][0] / B, by = queries[y][0] / B;
    if (bx != by) return bx < by;
    return (bx & 1) ? queries[x][1] > queries[y][1]
      : queries[x][1] < queries[y][1];
  });

  // ---- window state ----
  vector<int> cnt(m, 0);
  int distinct = 0;

  // Element at index i enters the window.
  auto add = [&] (int i) {
    if (cnt[a[i]]++ == 0) distinct++;   // value just appeared: 0 -> 1
  };
  // Element at index i leaves the window.
  auto rem = [&] (int i) {
    if (--cnt[a[i]] == 0) distinct--;   // value just vanished: 1 -> 0
  };

  // Empty window to start: curL = 0, curR = -1 means [0, -1] (no elements).
  int curL = 0, curR = -1;
  vector<int> ans(q);

  for (int idx : order) {
    int l = queries[idx][0], r = queries[idx][1];

    // IMPORTANT: expand first, then shrink.
    // If you shrink first, the window can become "negative" (curL > curR + 1)
    // and you would remove elements that were never added.
    while (curL > l) add(--curL);   // expand left
    while (curR < r) add(++curR);   // expand right
    while (curL < l) rem(curL++);   // shrink left
    while (curR > r) rem(curR--);   // shrink right

    ans[idx] = distinct;            // window is now exactly [l, r]
  }
  return ans;
}

/* ================================================================== */
/* PART 2: OFFLINE SWEEP + FENWICK TREE (BIT)                          */
/* ================================================================== */

// Standard Fenwick tree: point update, prefix sum. 1-indexed.
struct Fenwick {
  int n;
  vector<int> t;
  Fenwick(int n) : n(n), t(n + 1, 0) {}

  // Add v at position i.  O(log n)
  void update(int i, int v) {
    for (; i <= n; i += i & -i) t[i] += v;
  }
  // Sum of positions [1..i].  O(log n)
  int query(int i) const {
    int s = 0;
    for (; i > 0; i -= i & -i) s += t[i];
    return s;
  }
  // Sum of positions [l..r].  O(log n)
  int query(int l, int r) const {
    return query(r) - query(l - 1);
  }
};

/*
 * Idea: sweep r from left to right. Maintain a 0/1 array b (stored in the BIT) with
 *   b[i] = 1  iff  i is the LAST occurrence of a[i] within the prefix [1..r].
 * Each distinct value in the prefix contributes exactly one 1, at its rightmost spot.
 *
 * Why this is right for EVERY l at once:
 *   a value appears in [l, r]  <=>  its last occurrence (<= r) is >= l
 *   so the number of 1s in b[l..r] = number of distinct values in [l, r].
 *
 * Going from r-1 to r changes b in at most 2 places:
 *   - clear the previous last occurrence of a[r] (if it exists)
 *   - set position r
 *
 * So we answer every query with right endpoint r at the moment the sweep reaches r.
 *
 * Complexity: O((n + q) * log n).
 *
 * Limitation: works because "distinct count" = sum of per-position contributions
 * that depend only on r. Many other Mo's problems (mode, exactly-k-times, ...) don't fit.
 *
 * a       : compressed array (values in [0, m))
 * m       : number of distinct values after compression
 * queries : {l, r} pairs, 0-indexed inclusive
 */
vector<int> solveBIT(const vector<int>& a, int m, const vector<array<int, 2>>& queries) {
  int n = a.size(), q = queries.size();

  // Group queries by right endpoint: byR[r] = list of (l, query index).
  // This replaces sorting; the sweep visits r in increasing order anyway.
  vector<vector<pair<int, int>>> byR(n);
  for (int i = 0; i < q; i++) byR[queries[i][1]].push_back({ queries[i][0], i });

  Fenwick bit(n);                  // BIT positions are 1..n  (array index i -> position i+1)
  vector<int> last(m, -1);         // last[v] = last position of value v so far (-1 = unseen)
  vector<int> ans(q);

  for (int r = 0; r < n; r++) {
    int v = a[r];

    // v seen before: its old last-occurrence is no longer the last, clear it.
    if (last[v] != -1) bit.update(last[v] + 1, -1);

    // r is now the last occurrence of v in [0..r].
    bit.update(r + 1, +1);
    last[v] = r;

    // Answer all queries ending at r: count of 1s in [l, r].
    for (auto [l, idx] : byR[r]) ans[idx] = bit.query(l + 1, r + 1);
  }
  return ans;
}

/* ================================================================== */
/* Driver                                                              */
/* ================================================================== */
int main() {
  int n, q;
  scanf("%d %d", &n, &q);

  vector<int> a(n);
  for (int& x : a) scanf("%d", &x);
  int m = compress(a);             // values -> [0, m)

  vector<array<int, 2>> queries(q);
  for (auto& [l, r] : queries) {
    scanf("%d %d", &l, &r);
    l--; r--;                    // convert to 0-indexed
  }

  // Pick one solver. Fenwick is faster; Mo's is the more general technique.
  vector<int> ans = solveBIT(a, m, queries);
  // vector<int> ans = solveMo(a, m, queries);

#ifdef LOCAL
  // Sanity check when compiling with -DLOCAL: both solvers must agree.
  assert(solveMo(a, m, queries) == solveBIT(a, m, queries));
#endif

  for (int x : ans) printf("%d\n", x);
  return 0;
}
