#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/********************************************************/
/* Types & Type Aliases                                 */
/********************************************************/
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
#ifdef __SIZEOF_INT128__
using u128 = __uint128_t;
#endif

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
#ifdef __SIZEOF_INT128__
using i128 = __int128_t;
#endif

using usize = size_t;
using isize = ptrdiff_t;
using uptr = uintptr_t;
using iptr = intptr_t;

using f32 = float;
using f64 = double;
using f80 = long double;

#if __cplusplus >= 202002L
using u8c = char8_t;
#endif
using u16c = char16_t;
using u32c = char32_t;

using vi = vector<i64>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vi>;

using pi = pair<i64, i64>;
using ti = tuple<i64, i64, i64>;
using vpi = vector<pi>;

using mi = map<i64, i64>;
using si = set<i64>;
using msi = multiset<i64>;

using um = unordered_map<i64, i64>;
using us = unordered_set<i64>;

template <class K, class V> using mp = map<K, V>;
template <class K, class V> using ump = unordered_map<K, V>;

template <class T> using st = set<T>;
template <class T> using mst = multiset<T>;
template <class T> using ust = unordered_set<T>;

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <class T>
using ost = tree<pi, null_type, less<pi>, rb_tree_tag,
  tree_order_statistics_node_update>;
// i64 greater = sz(s) - s.order_of_key({ val, INF });
// i64 equal = s.order_of_key({ val, INF }) - s.order_of_key({ val, -INF });
// i64 less = s.order_of_key({ val, -INF });
// erase not remove

/********************************************************/
/* Utility Functions & Constants                        */
/********************************************************/
template <typename T> inline bool smin(T& a, const T& b) {
  return b < a ? a = b, true : false;
}
template <typename T> inline bool smax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}

constexpr int dir[5] = { 1, 0, -1, 0, 1 }; // dx = dir[i], dy = dir[i+1]
constexpr i32 imax = numeric_limits<i32>::max();
constexpr i32 imin = numeric_limits<i32>::min();
constexpr i64 lmax = numeric_limits<i64>::max();
constexpr i64 lmin = numeric_limits<i64>::min();
constexpr i64 INF = 4e18;
constexpr i64 mod1 = 1'000'000'007;
constexpr i64 mod2 = 998'244'353;
i64 mod = mod1;

inline void swap_mod() { mod = (mod == mod1) ? mod2 : mod1; }

inline i64 popcount(u64 x) { return __builtin_popcountll(x); }
inline i64 ctz(u64 x) { return x ? __builtin_ctzll(x) : 64; }
inline i64 clz(u64 x) { return x ? __builtin_clzll(x) : 64; }
inline i64 highbit(u64 x) { return x ? 63 - __builtin_clzll(x) : -1; }
inline i64 lowbit(u64 x) { return x ? __builtin_ctzll(x) : -1; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline i64 rnd(i64 lo, i64 hi) {
  return uniform_int_distribution<i64>(lo, hi)(rng);
}

constexpr int FP_PREC = 15;
template <typename T> void print_fp(T x, int precision = FP_PREC) {
  cout << fixed << setprecision(precision) << x << '\n';
}

/********************************************************/
/* Macros & Loop Helpers                                */
/********************************************************/
#define fo(i, x, y) for (i64 i = (x); i < (y); ++i)
#define foi(i, x, y, inc) for (i64 i = (x); i < (y); i += (inc))
#define fr(i, x, y) for (i64 i = (x); i >= (y); --i)
#define frd(i, x, y, dec) for (i64 i = (x); i >= (y); i -= (dec))
#define trav(a, b) for (auto& a : (b))
#define CA const auto&

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define alln(x, n) (x), (x) + (n)

#define yes cout << "Yes\n"
#define no cout << "No\n"

/********************************************************/
/* Debug System Setup (uses cout — visible in LeetCode's */
/* console, unlike cerr)                                 */
/********************************************************/
#define DEBUG_MODE 1

#if DEBUG_MODE
#define sl cout << string(20, '-') << "\n"
#define bl cout << string(40, '-') << "\n"
#else
#define sl
#define bl
#endif

template <typename T> void _print(T t) { cout << t; }
template <typename T, typename... Args> void _print(T t, Args... args) {
  cout << t << " ";
  _print(args...);
}
template <class T, class V> void _print(pair<T, V> p) {
  cout << "{";
  _print(p.ff);
  cout << " ";
  _print(p.ss);
  cout << "}";
}

template <class Tuple, size_t... Is>
void _print_tuple_impl(const Tuple& t, index_sequence<Is...>) {
  cout << "{";
  size_t idx = 0;
  ((cout << (idx++ ? " " : ""), _print(get<Is>(t))), ...);
  cout << "}";
}
template <class... Args> void _print(const tuple<Args...>& t) {
  _print_tuple_impl(t, index_sequence_for<Args...>{});
}

template <class T> void _print(vector<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
inline void _print(const vector<bool>& v) {
  cout << "[ ";
  for (bool b : v)
    cout << b << " ";
  cout << "]";
}
template <class T, size_t N> void _print(const T(&arr)[N]) {
  cout << "[ ";
  fo(idx, 0, (int)N) {
    _print(arr[idx]);
    cout << " ";
  }
  cout << "]";
}
template <class T, size_t N> void _print(const array<T, N>& arr) {
  cout << "[ ";
  trav(i, arr) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(vector<vector<T>> v) {
  trav(i, v) {
    cout << "\n";
    _print(i);
  }
}
template <class T> void _print(set<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(multiset<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(unordered_set<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(unordered_map<T, V> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template<class T> void _print(stack<T> s) {
  vector<T> t;
  while (!s.empty()) { t.pb(s.top()); s.pop(); }
  cout << "[ ";
  while (!t.empty()) {
    _print(t.back()); cout << " "; s.push(t.back()); t.pop_back();
  }
  cout << "]";
}
template <class T> void _print(queue<T> q) {
  vector<T> t;
  cout << "[ ";
  while (!q.empty()) {
    _print(q.front());
    cout << " ";
    t.pb(q.front());
    q.pop();
  }
  cout << "]";
  trav(i, t) q.push(i);
}
template <class T> void _print(pq<T> pqq) {
  vector<T> t;
  cout << "[ ";
  while (!pqq.empty()) {
    _print(pqq.top());
    cout << " ";
    t.pb(pqq.top());
    pqq.pop();
  }
  cout << "]";
  trav(i, t) pqq.push(i);
}
template <class T> void _print(pqg<T> pqq) {
  vector<T> t;
  cout << "[ ";
  while (!pqq.empty()) {
    _print(pqq.top());
    cout << " ";
    t.pb(pqq.top());
    pqq.pop();
  }
  cout << "]";
  trav(i, t) pqq.push(i);
}

#if DEBUG_MODE
inline vector<string> _dbg_split(const string& s) {
  vector<string> res;
  string cur;
  int depth = 0;
  trav(c, s) {
    if (c == '(' || c == '[' || c == '{')
      depth++;
    if (c == ')' || c == ']' || c == '}')
      depth--;
    if (c == ',' && depth == 0) {
      res.pb(cur);
      cur.clear();
    } else
      cur += c;
  }
  res.pb(cur);
  trav(t, res) {
    size_t a = t.find_first_not_of(" \t");
    size_t b = t.find_last_not_of(" \t");
    t = (a == string::npos) ? "" : t.substr(a, b - a + 1);
  }
  return res;
}
template <typename T> struct _DbgNamed {
  const char* name;
  T value;
};
template <typename T> _DbgNamed<T> nm(const char* name, T value) {
  return _DbgNamed<T>{name, value};
}
template <typename T> void _dbg_one(const string& fallback, const T& x) {
  cout << fallback << " = ";
  _print(x);
}
template <typename T>
void _dbg_one(const string& fallback, const _DbgNamed<T>& x) {
  (void)fallback;
  cout << x.name << " = ";
  _print(x.value);
}
inline void _dbg_print_all(vector<string>::iterator) { cout << "\n"; }
template <typename T, typename... Args>
void _dbg_print_all(vector<string>::iterator it, T&& first, Args&&... rest) {
  _dbg_one(*it, first);
  if (sizeof...(rest) > 0)
    cout << ", ";
  _dbg_print_all(++it, rest...);
}
#define dbg(...)                                                               \
    do {                                                                       \
        auto _dbg_names = _dbg_split(#__VA_ARGS__);                            \
        _dbg_print_all(_dbg_names.begin(), __VA_ARGS__);                       \
    } while (0)
#else
#define dbg(...)
#endif

/********************************************************/
/* ListNode / TreeNode                                  */
/* LOCAL-only (compile with -DLOCAL): LeetCode's judge   */
/* already declares these, so leaving LOCAL undefined on */
/* submission skips this block and avoids redefinition.  */
/********************************************************/
#ifdef LOCAL
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x), left(left), right(right) {
  }
};
#endif

/********************************************************/
/* Generic List / Tree Helpers (templated on Node, so    */
/* they bind to either the LOCAL structs above or         */
/* LeetCode's own ListNode/TreeNode)                      */
/********************************************************/
template <class Node> void printList(Node* head) {
  cout << "[ ";
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << "]\n";
}

template <class Node> Node* buildList(const vi& v) {
  Node dummy(0);
  Node* cur = &dummy;
  trav(x, v) {
    cur->next = new Node(x);
    cur = cur->next;
  }
  return dummy.next;
}

template <class Node> void freeList(Node* head) {
  while (head) {
    Node* nxt = head->next;
    delete head;
    head = nxt;
  }
}

template <class Node> void printTree(Node* root, int depth = 0) {
  if (!root) {
    cout << string(depth * 2, ' ') << "null\n";
    return;
  }
  cout << string(depth * 2, ' ') << root->val << "\n";
  if (root->left || root->right) {
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
  }
}

// Level-order build; `sentinel` (default INT_MIN) marks a missing child,
// e.g. {1,2,3,INT_MIN,4}.
template <class Node>
Node* buildTree(const vector<int>& v, int sentinel = INT_MIN) {
  if (v.empty() || v[0] == sentinel)
    return nullptr;
  Node* root = new Node(v[0]);
  queue<Node*> q;
  q.push(root);
  size_t i = 1;
  while (i < v.size() && !q.empty()) {
    Node* cur = q.front();
    q.pop();
    if (i < v.size()) {
      if (v[i] != sentinel) {
        cur->left = new Node(v[i]);
        q.push(cur->left);
      }
      i++;
    }
    if (i < v.size()) {
      if (v[i] != sentinel) {
        cur->right = new Node(v[i]);
        q.push(cur->right);
      }
      i++;
    }
  }
  return root;
}

template <class Node> void freeTree(Node* root) {
  if (!root)
    return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

/********************************************************/
/* Math Helpers                                         */
/********************************************************/
inline i64 mulmod(i64 a, i64 b, i64 m = mod) {
#if defined(__SIZEOF_INT128__)
  return (__int128)a * b % m;
#else
  i64 res = 0;
  a %= m;
  while (b > 0) {
    if (b & 1)
      res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
#endif
}

i64 power(i64 base, i64 exp, i64 m = mod) {
  i64 res = 1;
  base %= m;
  while (exp > 0) {
    if (exp & 1)
      res = mulmod(res, base, m);
    base = mulmod(base, base, m);
    exp >>= 1;
  }
  return res;
}

i64 inv(i64 a, i64 m = mod) { return power(a, m - 2, m); }
i64 madd(i64 a, i64 b, i64 m = mod) { return (a + b) % m; }
i64 msub(i64 a, i64 b, i64 m = mod) { return ((a - b) % m + m) % m; }
i64 mmul(i64 a, i64 b, i64 m = mod) { return mulmod(a, b, m); }
i64 mdiv(i64 a, i64 b, i64 m = mod) { return mulmod(a % m, inv(b, m), m); }

i64 custom_gcd(i64 a, i64 b) { return b ? custom_gcd(b, a % b) : a; }
i64 custom_lcm(i64 a, i64 b) { return a / custom_gcd(a, b) * b; }
i64 ceil_div(i64 a, i64 b) { return (a + b - 1) / b; }

i64 isqrt(i64 n) {
  if (n < 0)
    return -1;
  if (n == 0)
    return 0;
  i64 r = (i64)sqrtl((f80)n);
  while (r > 0 && r > n / r)
    r--;
  while ((r + 1) <= n / (r + 1))
    r++;
  return r;
}

template <typename T> T sign(T x) { return (x > 0) - (x < 0); }
template <class T> i32 sz(const T& c) { return static_cast<i32>(c.size()); }

/********************************************************/

static const int _fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // swap_mod();

  return 0;
}();

/********************************************************/

/*
=====================================================================
PART 1: YOUR ORIGINAL APPROACH (table + segment tree)
=====================================================================

PROBLEM
  Count triplets (i, j, k), i <= j < k, where
  distinct(s[i..j]) == distinct(s[j+1..k]).

SPLIT BY THE CUT j
  For every cut j (between j and j+1):
    L[d] = number of starts i <= j   such that s[i..j]   has exactly d distinct chars
    R[d] = number of ends   k >  j   such that s[j+1..k] has exactly d distinct chars
  Answer for cut j = L[1]*R[1] + L[2]*R[2] + L[3]*R[3] + ...
  Total answer     = sum over all cuts j.
  (The answer can reach ~1e14, so use long long.)

YOUR TABLE (RIGHT side)
  Column p holds R-counts for substrings STARTING at p: row d = number of ends k
  such that s[p..k] has exactly d distinct chars.
  Each cell is written as "d, count". It is built moving right -> left.

  s     = b   e   c   d   e   c   b   c   c   a   b   a   a
  index   0   1   2   3   4   5   6   7   8   9   10  11  12

  row1:  1,1 1,1 1,1 1,1 1,1 1,1 1,1 1,2 1,1 1,1 1,1 1,2 1,1
  row2:  2,1 2,1 2,1 2,1 2,1 2,3 2,2 2,1 2,1 2,3 2,2
  row3:  3,1 3,3 3,2 3,1 3,3 3,4 3,4 3,3 3,3
  row4:  4,6 4,3 4,3 4,3 4,4
  row5:  5,4 5,4 5,4 5,4

  Example: column 0 says that starting at b(0), there is 1 end with 1 distinct,
  1 end with 2 distinct, 1 end with 3, 6 ends with 4, 4 ends with 5. (1+1+1+6+4 = 13 = n)

MOVING LEFT: add char x = s[p] in front of column p+1 to get column p.
  A new first letter x affects the ends k as follows:
    - ends k BEFORE the next occurrence q of x: x is a brand new letter for that
      substring, so its distinct count goes up by 1 (the row index shifts down by 1).
    - ends k FROM q onward: x was already inside, so the distinct count is unchanged.
    - the new end k = p (substring "x" alone) adds 1 to row 1.

  CASE 1: same char as the immediate neighbour (s[p] == s[p+1])
          -> row 1 += 1, copy the rest.
          e.g. p=7 (c), p+1=8 (c): column 8 = (1,1,3) -> column 7 = (2,1,3)

  CASE 2: different char + UNSEEN (no occurrence to the right)
          -> new row 1 = 1, every old row shifts down by one
             (distinct count 2 becomes 3, and so on).
          e.g. p=4 (e): column 5 = (1,3,4) -> column 4 = (1,1,3,4)

  CASE 3: different char + SEEN
          let d = number of distinct chars from x up to its next occurrence q
                  (the window s[p+1..q-1] plus x itself).
          -> new row 1 = 1
          -> shift the first d-1 old rows down by one (they become rows 2..d)
          -> old row d (ends from q onward) does not shift, so it MERGES with
             the shifted old row d-1 into new row d
          -> rows after d are copied as they are.
          e.g. p=5 (c), next c at q=7, window "c b c" has d=2:
               column 6 = (1,2,4)
               new row1 = 1
               new row2 = old row1 (shifted) + old row2 (stays) = 1 + 2 = 3
               row3 copied = 4
               column 5 = (1,3,4)  <- matches the table

  LEFT side is the mirror image: moving left -> right, add char s[j] at the END of
  every substring s[i..j]. Same 3 cases, with "previous occurrence" instead of "next".

HOW YOUR APPROACH FINDS d: SEGMENT TREE
  Moving right -> left, mark in a segment tree the FIRST occurrence (at or after
  p+1) of every letter. When you meet x at p with next occurrence q:
      d = (number of marks in [p+1, q-1]) + 1      (the +1 is x itself)
      unmark q, mark p
  Cost: O(log n) per step -> O(26*n + n log n) overall.

  Check p=5 (c), q=7: marks are b@6, c@7, a@9. In [6,6] there is 1 mark (b),
  so d = 2.

=====================================================================
PART 2: REMOVING THE SEGMENT TREE (vector / stack of letters)
=====================================================================

  The marked positions are exactly the first occurrences of each distinct letter,
  so there are at most 26 marks at any time.

  Keep a list 'order' of letters sorted by those positions, nearest first:
      p=5 before processing: order = [b@6, c@7, a@9]

  Then:
    - marks in [p+1, q-1] = letters whose first occurrence is before q
                          = letters in front of x in the list
                          = index of x in the list
    - so d = index(x) + 1, found by scanning at most 26 items
    - "unmark q"  -> erase x from the list
    - "mark p"    -> insert x at the front (it is now the nearest)
    - x not in the list -> CASE 2 (unseen), d = 0
    - index(x) == 0     -> CASE 1 (same as neighbour), d = 1
    - otherwise         -> CASE 3

  Dry run p=5 (c): order=[b,c,a], c is at index 1, so d=2.
  Erase c, insert at the front: order=[c,b,a].

  The table update is IDENTICAL to Part 1. Only the way d is found changes:
      segment tree query O(log n)  ->  list scan O(26)
  Total: O(26*n) time, O(26*n) memory (about 11 MB for R).

  A std::vector is used instead of a plain stack because the erase happens in the
  middle. With a stack you would pop until x is found and push the popped letters
  back, which is the same O(26) work.

=====================================================================
PART 3: OPTIMISED CODE
=====================================================================
*/

class Solution {
  public:
  // Applies your 3 cases to a count table.
  // cnt[r] = number of substrings with exactly r distinct chars (r = 1..26)
  // d = 0  -> CASE 2 (different + unseen)
  // d = 1  -> CASE 1 (same as neighbour)
  // d >= 2 -> CASE 3 (different + seen)
  void applyStep(array<int, 27>& cnt, int d) {
    if (d == 0) {
      // CASE 2: every old row shifts down by one, new row 1 = 1
      fr(r, 26, 2) cnt[r] = cnt[r - 1];
      cnt[1] = 1;
    } else if (d == 1) {
      // CASE 1: row 1 grows by one, rest copied
      cnt[1]++;
    } else {
      // CASE 3: old rows 1..d-1 shift down to 2..d, old row d stays,
      // so new row d = old row d-1 + old row d.
      // Rows after d are untouched, new row 1 = 1.
      int merged = cnt[d - 1] + cnt[d];
      fr(r, d - 1, 2) cnt[r] = cnt[r - 1];
      cnt[d] = merged;
      cnt[1] = 1;
    }
  }

  // Replaces the segment tree.
  // 'order' = letters sorted by nearest occurrence (front = nearest).
  // Returns d (0 if the letter is unseen), then moves c to the front.
  int getRankAndMoveFront(vector<int>& order, int c) {
    int idx = -1;
    fo(i, 0, sz(order)) { // at most 26 steps
      if (order[i] == c) { idx = i; break; }
    }
    int d = 0;
    if (idx != -1) {
      d = idx + 1; // letters before c, plus c itself
      order.erase(order.begin() + idx); // "unmark old occurrence"
    }
    order.insert(order.begin(), c); // "mark new occurrence"
    return d;
  }

  long long countMagicalPairs(string s) {
    int n = sz(s);

    // ---------- RIGHT table (built right -> left) ----------
    // R[p][d] = number of ends k >= p such that s[p..k] has exactly d distinct chars
    vector<array<int, 27>> R(n + 1);
    R[n].fill(0);
    vector<int> orderR; // letters by next occurrence
    fr(p, n - 1, 0) {
      int d = getRankAndMoveFront(orderR, s[p] - 'a');
      R[p] = R[p + 1]; // start from column p+1
      applyStep(R[p], d); // apply case 1 / 2 / 3
    }

    // ---------- LEFT table (built left -> right) + combine ----------
    // cur[d] = number of starts i <= j such that s[i..j] has exactly d distinct chars
    array<int, 27> cur;
    cur.fill(0);
    vector<int> orderL; // letters by previous occurrence
    i64 res = 0;

    fo(j, 0, n - 1) { // cut after j, so j <= n-2
      int d = getRankAndMoveFront(orderL, s[j] - 'a');
      applyStep(cur, d); // same 3 cases, mirrored

      // right piece starts at j+1, so use column R[j+1]
      fo(k, 1, 27)
        res += (i64)cur[k] * R[j + 1][k]; // cast first to avoid overflow
    }
    
    return res;
  }
};
