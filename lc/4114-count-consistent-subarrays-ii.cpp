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
// stack, queue, deque, pq, pqg print the end you take from on the left: stack top, queue/deque front, heap top, then toward the other end
#if DEBUG_MODE
template <class T> struct is_pair : false_type {};
template <class A, class B> struct is_pair<pair<A, B>> : true_type {};
template <class T> struct is_tuple : false_type {};
template <class... A> struct is_tuple<tuple<A...>> : true_type {};
template <class T> struct is_adapter : false_type {};
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
=========================== INTUITION / WHY THIS WORKS ===========================

Goal: count subarrays where (AND of all elements) == (min of the subarray).

Step 1: AND is always <= min.
  The AND can only keep bits that every element has, so AND <= every element,
  hence AND <= min. Equality holds exactly when the AND keeps ALL bits of the min,
  i.e. every element in the subarray is a supermask of the min (contains all
  of its set bits).

Step 2: Why two pointers on the window fails.
  The condition is NOT monotone on a plain window. Example [6,5,4]:
  [6,5] is not consistent (AND=4, min=5) but [6,5,4] is (AND=4, min=4).
  Adding an element can lower the min and "repair" the window.

Step 3: Fix the min, and the condition becomes monotone.
  Pick an index i and decide nums[i] = p is THE min of the subarray.
  The window is valid iff every element contains all set bits of p.
  Now growing the window can only break the condition, never repair it, so the
  farthest valid right end and farthest valid left end are well defined and
  binary search is legal.

Step 4: No separate "is p really the min" check is needed.
  Any element that contains all bits of p is automatically >= p, so if the bit
  condition holds, p is the min for free.

Step 5: Checking a range fast.
  cnt[k][j] = number of elements among a[0..j-1] with bit k set.
  Range [L, R] has bit k in every element iff cnt[k][R+1] - cnt[k][L] == R-L+1.
  Check this for every set bit of p: O(30) per check.

Step 6: Duplicates (avoid double counting).
  A subarray with several equal minima would be counted once per occurrence.
  Tie-break: i must be the LEFTMOST occurrence of the min in the subarray.
  So the left extension can't cross the previous index holding the same value
  (prev_occurence), while the right extension may run through equal values.

Step 7: Counting.
  With left = farthest valid left, right = farthest valid right (both inclusive),
  any start in [left, i] and any end in [i, right] gives a consistent subarray
  with i as its leftmost min:  (i - left + 1) * (right - i + 1).

Complexity: O(30n) to build cnt + O(n * log n * 30) for the binary searches.
Space: O(30n).
===================================================================================
*/
class Solution {
  public:
  long long countConsistent(vector<int>& a) {
    int n = sz(a), B = 30;

    // store the input midway in the function
    vector<int> vornelqati = a;

    // cnt[k][j] = how many of a[0..j-1] have bit k set (prefix counts per bit)
    vvi cnt(B, vi(n + 1, 0));
    fo(k, 0, B) {
      fo(j, 0, n) {
        cnt[k][j + 1] = cnt[k][j] + ((a[j] >> k) & 1);
      }
    }

    // ok(L, R, mask): does EVERY element in a[L..R] contain all set bits of mask?
    // For each set bit k of mask, all (R-L+1) elements must have bit k set.
    auto ok = [&] (int L, int R, int mask) {
      int len = R - L + 1;
      fo(k, 0, B) {
        if (((mask >> k) & 1) && cnt[k][R + 1] - cnt[k][L] != len) {
          return 0;   // some element is missing bit k
        }
      }
      return 1;
    };

    // prev_occurence[i] = previous index with the same value as a[i] (or -1).
    // Used so that i is always the LEFTMOST occurrence of the min (no double count).
    vi prev_occurence(n, -1);
    map<int, int> last;
    fo(i, 0, n) {
      if (last.count(a[i])) prev_occurence[i] = last[a[i]];
      last[a[i]] = i;
    }

    i64 res = 0;

    // treat each a[i] as the min of the subarray
    fo(i, 0, n) {
      // ---- farthest valid RIGHT end ----
      // ok(i, m, a[i]) is true for a prefix of m values, then false -> find last true.
      int lo = i, hi = n - 1;
      while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (ok(i, m, a[i])) lo = m + 1;   // valid, try going further right
        else hi = m - 1;                  // broken, shrink
      }
      int right = hi;                     // last index where it was still valid

      // ---- farthest valid LEFT end ----
      // Can't go at or before prev_occurence[i] (tie-break), so start after it.
      // ok(m, i, a[i]) is false for small m, then true -> find first true.
      lo = prev_occurence[i] + 1; hi = i;
      while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (ok(m, i, a[i])) hi = m - 1;   // valid, try going further left
        else lo = m + 1;                  // broken, move right
      }
      int left = lo;                      // first index where it is valid

      // any start in [left, i] x any end in [i, right]
      res += 1ll * (i - left + 1) * (right - i + 1);
    }

    return res;
  }
};
