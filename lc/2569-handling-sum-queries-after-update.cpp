#define DEBUG_MODE 1

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

/********************************************************/
/* Types & Aliases                                      */
/********************************************************/
using u8 = uint8_t;   using u16 = uint16_t;  using u32 = uint32_t;  using u64 = uint64_t;
using i8 = int8_t;    using i16 = int16_t;   using i32 = int32_t;   using i64 = int64_t;
#ifdef __SIZEOF_INT128__
using u128 = __uint128_t;
using i128 = __int128_t;
#else
using u128 = u64;
using i128 = i64;
#endif
using f32 = float;  using f64 = double;  using f80 = long double;

using vi = vector<i64>;   using vvi = vector<vi>;
using vb = vector<bool>;  using vc = vector<char>;  using vs = vector<string>;
using pii = pair<i64, i64>;  using tii = tuple<i64, i64, i64>;
using vpi = vector<pii>;

struct chash {
  static u64 sm(u64 x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
  }
  size_t operator()(u64 x) const {
    static const u64 R = chrono::steady_clock::now().time_since_epoch().count();
    return sm(x + R);
  }
  template <class A, class B> size_t operator()(const pair<A, B>& p) const {
    return sm((*this)(p.first) * 31 + (*this)(p.second));
  }
};
template <class K, class V> using UMap = unordered_map<K, V, chash>;
template <class K> using USet = unordered_set<K, chash>;
template <class K, class V> using Map = map<K, V>;
template <class K> using Set = set<K>;
template <class K> using MSet = multiset<K>;
template <class T> using PQ = priority_queue<T>;
template <class T> using PQG = priority_queue<T, vector<T>, greater<T>>;
// order statistics set. OST<i64> s; s.insert(x); s.find_by_order(k) -> iterator to k-th smallest (0-indexed)
// s.order_of_key(x) -> count of elements < x. No duplicates: insert pair{x, unique_id} for multiset behaviour
template <class T> using OST = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/********************************************************/
/* Constants & Small Utilities                          */
/********************************************************/
constexpr int dir[5] = { 1, 0, -1, 0, 1 };
constexpr i32 imax = numeric_limits<i32>::max();
constexpr i32 imin = numeric_limits<i32>::min();
constexpr i64 lmax = numeric_limits<i64>::max();
constexpr i64 lmin = numeric_limits<i64>::min();
constexpr i64 INF = 2'000'000'000'000'000'000LL;
constexpr i64 MOD1 = 1'000'000'007;
constexpr i64 MOD2 = 998'244'353;
constexpr i64 MOD = MOD1;

template <class T> inline bool smin(T& a, const T& b) { return b < a ? (a = b, true) : false; }
template <class T> inline bool smax(T& a, const T& b) { return a < b ? (a = b, true) : false; }
template <class T> inline i32 sz(const T& c) { return (i32)c.size(); }
template <class T> inline T sign(T x) { return (x > 0) - (x < 0); }

inline i64 popcount(u64 x) { return __builtin_popcountll(x); }
inline i64 ctz(u64 x) { return x ? __builtin_ctzll(x) : 64; }
inline i64 clz(u64 x) { return x ? __builtin_clzll(x) : 64; }
inline i64 lg(u64 x) { return x ? 63 - __builtin_clzll(x) : -1; }
inline bool bit(u64 x, int i) { return (x >> i) & 1; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline i64 rnd(i64 lo, i64 hi) { return uniform_int_distribution<i64>(lo, hi)(rng); }

inline void yn(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YN(bool b) { cout << (b ? "YES" : "NO") << '\n'; }

template <class T> void print_fp(T x, int precision = 15) {
  cout << fixed << setprecision(precision) << x << '\n';
}

/********************************************************/
/* Macros                                               */
/********************************************************/
#define fo(i, x, y, ...) for (i64 i = (x); i < (y); i += (1 __VA_OPT__(* 0 + (__VA_ARGS__))))
#define fr(i, x, y, ...) for (i64 i = (x); i >= (y); i -= (1 __VA_OPT__(* 0 + (__VA_ARGS__))))
#define fox(i, x, y, expr) for (i64 i = (x); i < (y); i = (expr))
#define frx(i, x, y, expr) for (i64 i = (x); i >= (y); i = (expr))
#define trav(a, b) for (auto& a : b)
#define CA const auto&
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

/********************************************************/
/* Debug (stdout, compiled out if DEBUG_MODE is 0)      */
/********************************************************/
// DEBUG_MODE 1 = debug prints go to stdout.
// dbg(a, b, v) prints "a = .., b = .., v = [..]" to stdout; works on vectors, maps, pairs, tuples, stacks, pq etc.
// stack, queue, deque print in push order (oldest on the left, newest on the right); pq, pqg print with top on the right
// sl / bl print a short / long dashed line to stdout
#if DEBUG_MODE
template <class T> struct is_pair : false_type {};
template <class A, class B> struct is_pair<pair<A, B>> : true_type {};
template <class T> struct is_tuple : false_type {};
template <class... A> struct is_tuple<tuple<A...>> : true_type {};
template <class T> struct is_adapter : false_type {};
template <class T> struct is_queue : false_type {};
template <class T, class C> struct is_queue<queue<T, C>> : true_type {};
template <class T, class C> struct is_adapter<stack<T, C>> : true_type {};
template <class T, class C> struct is_adapter<queue<T, C>> : true_type {};
template <class T, class C, class P> struct is_adapter<priority_queue<T, C, P>> : true_type {};
template <class T, class = void> struct is_iter : false_type {};
template <class T> struct is_iter<T, void_t<decltype(begin(declval<T&>())), decltype(end(declval<T&>()))>> : true_type {};

template <class T, class C> T _top(const stack<T, C>& s) { return s.top(); }
template <class T, class C> T _top(const queue<T, C>& s) { return s.front(); }
template <class T, class C, class P> T _top(const priority_queue<T, C, P>& s) { return s.top(); }

template <class T> void _print(const T& x) {
  if constexpr (is_same_v<T, string>) cout << '"' << x << '"';
  else if constexpr (is_same_v<T, char>) cout << '\'' << x << '\'';
  else if constexpr (is_same_v<T, bool>) cout << (x ? "true" : "false");
#ifdef __SIZEOF_INT128__
  else if constexpr (is_same_v<T, i128> || is_same_v<T, u128>) {
    if (x == 0) { cout << 0; return; }
    string s; T y = x; bool neg = false;
    if constexpr (is_same_v<T, i128>) if (y < 0) { neg = true; y = -y; }
    while (y > 0) { s += char('0' + (int)(y % 10)); y /= 10; }
    if (neg) s += '-';
    reverse(all(s)); cout << s;
  }
#endif
  else if constexpr (is_pair<T>::value) {
    cout << "{"; _print(x.first); cout << ", "; _print(x.second); cout << "}";
  } else if constexpr (is_tuple<T>::value) {
    cout << "{";
    apply([] (const auto&... e) { size_t i = 0; ((cout << (i++ ? ", " : ""), _print(e)), ...); }, x);
    cout << "}";
  } else if constexpr (is_adapter<T>::value) {
    T c = x; vector<decay_t<decltype(_top(c))>> v;
    while (!c.empty()) { v.push_back(_top(c)); c.pop(); }
    if constexpr (!is_queue<T>::value) reverse(all(v));
    _print(v);
  } else if constexpr (is_iter<T>::value) {
    cout << "["; bool first = true;
    for (const auto& e : x) { if (!first) cout << ", "; first = false; _print(e); }
    cout << "]";
  } else cout << x;
}

inline vector<string> _dbg_split(const string& s) {
  vector<string> res; string cur; int depth = 0;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;
    if (c == ',' && depth == 0) { res.pb(cur); cur.clear(); } else cur += c;
  }
  res.pb(cur);
  for (auto& t : res) {
    size_t a = t.find_first_not_of(" \t"), b = t.find_last_not_of(" \t");
    t = (a == string::npos) ? "" : t.substr(a, b - a + 1);
  }
  return res;
}
template <class... A> void _dbg_impl(const vector<string>& names, const A&... a) {
  size_t i = 0;
  ((cout << names[i++] << " = ", _print(a), cout << (i < sizeof...(A) ? ", " : "\n")), ...);
}
#define dbg(...) do { auto _n = _dbg_split(#__VA_ARGS__); _dbg_impl(_n, __VA_ARGS__); } while (0)
inline void dsep(int n = 40) { cout << string(n, '-') << "\n"; }
#define sl dsep(20)
#define bl dsep(40)
#else
#define dbg(...) ((void)0)
inline void dsep(int = 40) {}
#define sl
#define bl
#endif

/********************************************************/
/* ListNode / TreeNode                                  */
/********************************************************/
// Only defined with -DLOCAL: LeetCode already declares these, so skipping them on submit avoids redefinition
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
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

/********************************************************/
/* List / Tree Helpers                                  */
/********************************************************/
// Templated on Node so they work with LeetCode's own ListNode/TreeNode too. Call with the type: buildList<ListNode>({1, 2, 3})
// printList(head) -> [ 1 2 3 ] | buildList<ListNode>(v) -> list from vector | freeList(head) -> delete the list
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

// printTree(root) -> indented print, one node per line | buildTree<TreeNode>({1, 2, 3, INT_MIN, 4}) -> level-order build
// INT_MIN marks a missing child (change with the second argument) | freeTree(root) -> delete the tree
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

template <class Node>
Node* buildTree(const vector<int>& v, int sentinel = INT_MIN) {
  if (v.empty() || v[0] == sentinel) return nullptr;
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
  if (!root) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

/********************************************************/
/* Math                                                 */
/********************************************************/
// Result type of mulmod/power: i64 for integer inputs, f64/f80 for floating inputs (f32 is promoted to f64)
template <class... T> using NumR = conditional_t<is_floating_point_v<common_type_t<T...>>,
  conditional_t<is_same_v<common_type_t<T...>, f32>, f64, common_type_t<T...>>, i64>;

template <class R> inline R _md(R a, R m) {
  if constexpr (is_floating_point_v<R>) a = fmod(a, m); else a %= m;
  return a < 0 ? a + m : a;
}

// mulmod(a, b)    -> a * b, no mod. Integers: returns -1 if the product overflows i64. Floats: plain a * b
// mulmod(a, b, m) -> a * b % m, no overflow even for m up to 9e18 (a and b already in [0, m)). Floats use fmod
template <class A, class B> inline NumR<A, B> mulmod(A a, B b) {
  using R = NumR<A, B>;
  if constexpr (is_floating_point_v<R>) return (R)a * (R)b;
  else { i64 r; return __builtin_mul_overflow((i64)a, (i64)b, &r) ? -1 : r; }
}
template <class A, class B, class M> inline NumR<A, B, M> mulmod(A a, B b, M m) {
  using R = NumR<A, B, M>;
  if constexpr (is_floating_point_v<R>) return fmod((R)a * (R)b, (R)m);
  else {
    if (m < (1LL << 31)) return (i64)a * (i64)b % (i64)m;
    return (i64)((i128)a * b % m);
  }
}

// power(b, e)    -> b^e, no mod. Integers: returns -1 if the result overflows i64 (or e < 0). Floats: plain result, e may be negative
// power(b, e, m) -> b^e % m (e >= 0). Floats: fmod of the plain result, so precision drops if b^e is huge
// power(2, 10) -> i64 | power(1.5, 3) -> f64 | power(1.5L, 3) -> f80
template <class A> inline NumR<A> power(A b, i64 e) {
  using R = NumR<A>;
  if constexpr (is_floating_point_v<R>) {
    bool neg = e < 0; if (neg) e = -e;
    R r = 1, x = b;
    for (; e > 0; e >>= 1, x *= x) if (e & 1) r *= x;
    return neg ? 1 / r : r;
  } else {
    if (e < 0) return -1;
    i64 r = 1, x = b;
    while (e > 0) {
      if ((e & 1) && __builtin_mul_overflow(r, x, &r)) return -1;
      e >>= 1;
      if (e > 0 && __builtin_mul_overflow(x, x, &x)) return -1;
    }
    return r;
  }
}
template <class A, class M> inline NumR<A, M> power(A b, i64 e, M m) {
  using R = NumR<A, M>;
  if constexpr (is_floating_point_v<R>) return fmod(power((R)b, e), (R)m);
  else {
    R x = _md((R)b, (R)m), r = _md((R)1, (R)m);
    for (; e > 0; e >>= 1, x = mulmod(x, x, (R)m)) if (e & 1) r = mulmod(r, x, (R)m);
    return r;
  }
}
inline i64 ceil_div(i64 a, i64 b) { return a / b + ((a % b != 0) && ((a < 0) == (b < 0))); }
inline i64 floor_div(i64 a, i64 b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }
inline i64 isqrt(i64 n) {
  if (n < 0) return -1;
  i64 x = (i64)sqrtl((f80)n);
  while ((i128)x * x > n) x--;
  while ((i128)(x + 1) * (x + 1) <= n) x++;
  return x;
}

template <u32 M> struct ModInt {
  u32 v;
  constexpr ModInt(i64 x = 0) : v((u32)(((x % (i64)M) + M) % M)) {}
  ModInt& operator+=(const ModInt& o) { v += o.v; if (v >= M) v -= M; return *this; }
  ModInt& operator-=(const ModInt& o) { v += M - o.v; if (v >= M) v -= M; return *this; }
  ModInt& operator*=(const ModInt& o) { v = (u64)v * o.v % M; return *this; }
  ModInt pow(u64 e) const { ModInt r = 1, b = *this; for (; e; e >>= 1, b *= b) if (e & 1) r *= b; return r; }
  ModInt inv() const { return pow(M - 2); }
  ModInt& operator/=(const ModInt& o) { return *this *= o.inv(); }
  friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }
  ModInt operator-() const { return ModInt() - *this; }
  friend bool operator==(const ModInt& a, const ModInt& b) { return a.v == b.v; }
  friend bool operator!=(const ModInt& a, const ModInt& b) { return a.v != b.v; }
  friend istream& operator>>(istream& is, ModInt& a) { i64 x; is >> x; a = ModInt(x); return is; }
  friend ostream& operator<<(ostream& os, const ModInt& a) { return os << a.v; }
};
using Mint1 = ModInt<1'000'000'007>;
using Mint2 = ModInt<998'244'353>;

/********************************************************/



static bool init_state = [] () {


  return true;
}();

static const int _fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);



  return 0;
}();

/********************************************************/

/*
 * ============================================================
 * APPROACH
 * ============================================================
 *
 * Reduce the problem:
 *   Type 2 does nums2[i] += nums1[i] * p for every i. Since nums1[i] is 0 or 1,
 *   the total sum of nums2 grows by exactly:
 *
 *       p * (number of ones currently in nums1)
 *
 *   Type 3 only asks for sum(nums2), never individual elements, so we never
 *   need to maintain nums2 itself. We keep one running number:
 *
 *       total = sum(nums2)         (initially)
 *       type 2:  total += p * ones(nums1)
 *       type 3:  answer = total
 *
 *   So the whole problem collapses to one question:
 *   "how many ones are in nums1 right now, given range flips?"
 *
 * Why not simulate directly?
 *   A range flip costs O(r - l + 1). With n, q up to 1e5 that is O(n * q) = 1e10
 *   in the worst case. Too slow.
 *
 * Why a segment tree with lazy propagation?
 *   - We need a range update (flip [l, r]) and a global aggregate (count of ones).
 *   - Flipping a segment of length len with c1 ones gives len - c1 ones
 *     (equivalently: swap c0 and c1). That transformation depends only on the
 *     segment's own counts, so it can be applied to a whole node in O(1)
 *     without touching its children.
 *   - Flips compose as XOR: two flips cancel. So a single bit `flip` per node
 *     is enough to remember "my children still owe a flip".
 *   - Each update visits O(log n) nodes: fully covered nodes are flipped in O(1)
 *     and the flip is deferred (lazy) for their subtrees.
 *
 * Node data:
 *   c0   = number of zeros in this segment
 *   c1   = number of ones in this segment
 *   flip = pending flip not yet pushed to the children
 *          (this node's own c0/c1 are already up to date)
 *
 * Operations:
 *   applyFlip(i): swap(c0, c1), flip ^= 1               -> O(1)
 *   push(i):      pass the pending flip down to both children, clear own flag
 *   pull(i):      c0, c1 = sum of the children's c0, c1
 *   flip(l, r):   fully covered -> applyFlip and stop
 *                 partial       -> push, recurse into both children, pull
 *
 * Answering queries:
 *   type 1: segment tree range flip
 *   type 2: total += p * root.c1
 *   type 3: push total into the answer
 *
 * Overflow: total can reach about 1e5 * 1e9 + 1e5 * 1e6 * 1e5 = ~1e16,
 * so everything is i64 (long long).
 *
 * Complexity: O(n + q log n) time, O(n) space.
 * ============================================================
 */
class Solution {
  public:

  int n;

  // Segment tree node (stored by value, not by pointer, so each node is distinct)
  struct Node {
    int c0 = 0;    // number of zeros in the segment
    int c1 = 0;    // number of ones in the segment
    int flip = 0;  // lazy flag: 1 if children still need to be flipped
  };

  vector<Node> ST;

  // Recompute a node from its two children
  void pull(int i) {
    ST[i].c0 = ST[2 * i].c0 + ST[2 * i + 1].c0;
    ST[i].c1 = ST[2 * i].c1 + ST[2 * i + 1].c1;
  }

  // Flip an entire node in O(1): zeros and ones swap, and mark the lazy flag.
  // Two flips cancel, hence XOR.
  void applyFlip(int i) {
    swap(ST[i].c0, ST[i].c1);
    ST[i].flip ^= 1;
  }

  // Push a pending flip down to the children, then clear it on this node.
  // This node's own counts were already updated when the flag was set.
  void push(int i) {
    if (ST[i].flip) {
      applyFlip(2 * i);
      applyFlip(2 * i + 1);
      ST[i].flip = 0;
    }
  }

  // Build the tree over a[s..e]; leaves hold a single bit
  void build(int i, int s, int e, vector<int>& a) {
    if (s == e) {
      ST[i].c0 = a[s] == 0;
      ST[i].c1 = a[s] == 1;
      return;
    }
    int m = s + (e - s) / 2;
    build(2 * i, s, m, a);
    build(2 * i + 1, m + 1, e, a);
    pull(i);
  }

  // Flip every element in [l, r]; node i covers [s, e]
  void flip(int i, int s, int e, int l, int r) {
    // No overlap: nothing to do
    if (r < s || e < l) return;

    // Fully covered: flip lazily in O(1), don't descend
    if (l <= s && e <= r) {
      applyFlip(i);
      return;
    }

    // Partial overlap: settle the pending flip first so the children are
    // accurate, then recurse and recombine
    push(i);
    int m = s + (e - s) / 2;
    flip(2 * i, s, m, l, r);
    flip(2 * i + 1, m + 1, e, l, r);
    pull(i);
  }

  vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
    vector<vector<int>>& queries) {
    n = sz(nums1);

    // 4n nodes is a safe upper bound for a recursive segment tree
    ST.assign(4 * n, Node());
    build(1, 0, n - 1, nums1);

    // Running sum of nums2; individual elements are never needed
    i64 total = accumulate(all(nums2), 0ll);
    vector<long long> res;

    trav(q, queries) {
      int type = q[0];
      if (type == 1) {
        // Range flip on nums1
        flip(1, 0, n - 1, q[1], q[2]);
      } else if (type == 2) {
        // Each 1 in nums1 adds p to its nums2 element, so the sum grows
        // by p * (ones in nums1). The root's c1 is that count.
        total += (i64)q[1] * ST[1].c1;
      } else {
        // Sum of nums2 is simply the running total
        res.pb(total);
      }
    }

    return res;
  }
};
