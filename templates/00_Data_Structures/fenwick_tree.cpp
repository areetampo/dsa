// Fenwick Tree (Binary Indexed Tree) — point updates, prefix sums, range
// sums, and k-th element search by descent. 1-indexed internally.
//
// Complexity: add/sum/query/kth are all O(log n) per call; build is O(n log n).
//
// Usage:
//   Fenwick fw(n);               // n elements, all initially 0
//   fw.add(3, 5);                // a[3] += 5
//   fw.sum(5);                   // prefix sum a[1..5]
//   fw.query(2, 5);              // range sum a[2..5]
//   fw.setVal(3, cur, val);      // set a[3] = val, given its current value
//   fw.kth(k);                   // smallest idx with sum(1..idx) >= k
//
// Counting / order-statistics usage (multiset over compressed values):
//   Fenwick cnt(m);              // m = number of distinct compressed values
//   cnt.add(rank(v), 1);         // insert v
//   cnt.add(rank(v), -1);        // erase v
//   cnt.kth(r);                  // compressed index of the r-th smallest element
//   cnt.sum(p);                  // number of elements with compressed index <= p
//
//   vi a(n + 1); // 1-indexed, a[0] unused
//   fw.build(a);

struct Fenwick {
  i64 n, top; // top = highest power of two <= n (used by kth)
  vi bit;

  Fenwick() {}
  Fenwick(i64 n) { init(n); }

  void init(i64 size) {
    n = size;
    bit.assign(n + 1, 0);
    top = 1;
    while (top * 2 <= n) top *= 2;
  }

  // Add val to index idx (1-indexed).
  void add(i64 idx, i64 val) {
    for (; idx <= n; idx += idx & -idx)
      bit[idx] += val;
  }

  // Prefix sum over [1..idx].
  i64 sum(i64 idx) const {
    i64 res = 0;
    for (; idx > 0; idx -= idx & -idx)
      res += bit[idx];
    return res;
  }

  // Range sum over [l..r], inclusive both ends (1-indexed).
  i64 query(i64 l, i64 r) const {
    if (l > r) return 0;
    return sum(r) - sum(l - 1);
  }

  // Smallest index p such that sum(1..p) >= k  (1 <= k).
  // Requires every stored value to be >= 0 (e.g. counts), so prefix sums
  // are monotonic. Returns n + 1 if k > sum(1..n).
  // Single O(log n) descent, no binary search + prefix query needed ((logn)^2).
  i64 kth(i64 k) const {
    i64 pos = 0;
    for (i64 b = top; b > 0; b >>= 1) {
      i64 np = pos + b;
      if (np <= n && bit[np] < k) {
        pos = np;
        k -= bit[np];
      }
    }
    return pos + 1;
  }

  // Set a[idx] = val, given its current value cur.
  // Fenwick only stores deltas, so caller tracks current values.
  void setVal(i64 idx, i64 cur, i64 val) {
    add(idx, val - cur);
  }

  // Build from an already-1-indexed vector: a[0] is ignored.
  void build(const vi& a) {
    init(sz(a) - 1);
    fo(i, 1, n + 1) add(i, a[i]);
  }
};


// Fenwick Tree for prefix maximum.
//
// Supports:
//   update(i, x) -> a[i] = max(a[i], x)
//   query(i)     -> max(a[1..i])
//
// IMPORTANT: values can only increase. A previously stored maximum cannot
// be removed, so arbitrary assignments/decreasing updates are not supported.
//
// Complexity: update/query O(log n), build O(n log n).
//
// Usage:
//   FenwickMax fw(n);
//   fw.update(3, 10);             // a[3] = max(a[3], 10)
//   fw.query(5);                  // max(a[1..5])
//   fw.build(a);                  // build from 1-indexed vector

struct FenwickMax {
  i64 n;
  vi bit;

  FenwickMax() {}
  FenwickMax(i64 n) { init(n); }

  void init(i64 size) {
    n = size;
    bit.assign(n + 1, LLONG_MIN);
  }

  // Increase index idx's value to at least val.
  void update(i64 idx, i64 val) {
    for (; idx <= n; idx += idx & -idx)
      bit[idx] = max(bit[idx], val);
  }

  // Prefix maximum over [1..idx].
  i64 query(i64 idx) const {
    i64 res = LLONG_MIN;
    for (; idx > 0; idx -= idx & -idx)
      res = max(res, bit[idx]);
    return res;
  }

  // Build from an already-1-indexed vector: a[0] is ignored.
  void build(const vi& a) {
    init(sz(a) - 1);
    fo(i, 1, n + 1) update(i, a[i]);
  }
};


// Fenwick Tree for prefix minimum.
//
// Supports:
//   update(i, x) -> a[i] = min(a[i], x)
//   query(i)     -> min(a[1..i])
//
// IMPORTANT: values can only decrease. A previously stored minimum cannot
// be removed, so arbitrary assignments/increasing updates are not supported.
//
// Complexity: update/query O(log n), build O(n log n).
//
// Usage:
//   FenwickMin fw(n);
//   fw.update(3, 10);             // a[3] = min(a[3], 10)
//   fw.query(5);                  // min(a[1..5])
//   fw.build(a);                  // build from 1-indexed vector

struct FenwickMin {
  i64 n;
  vi bit;

  FenwickMin() {}
  FenwickMin(i64 n) { init(n); }

  void init(i64 size) {
    n = size;
    bit.assign(n + 1, LLONG_MAX);
  }

  // Decrease index idx's value to at most val.
  void update(i64 idx, i64 val) {
    for (; idx <= n; idx += idx & -idx)
      bit[idx] = min(bit[idx], val);
  }

  // Prefix minimum over [1..idx].
  i64 query(i64 idx) const {
    i64 res = LLONG_MAX;
    for (; idx > 0; idx -= idx & -idx)
      res = min(res, bit[idx]);
    return res;
  }

  // Build from an already-1-indexed vector: a[0] is ignored.
  void build(const vi& a) {
    init(sz(a) - 1);
    fo(i, 1, n + 1) update(i, a[i]);
  }
};
