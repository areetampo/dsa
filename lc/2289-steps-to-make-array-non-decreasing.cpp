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
template <class T> inline i64 sz(const T& c) { return (i64)c.size(); }
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
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

/********************************************************/
/* Debug (stdout, compiled out if DEBUG_MODE is 0)      */
/********************************************************/
// DEBUG_MODE 1 = debug prints go to stdout (visible in the LeetCode console). Set to 0 before final submit if output is heavy.
// Everything in this block is debug printing; no need to read it.
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
inline i64 mulmod(i64 a, i64 b, i64 m) {
  if (m < (1LL << 31)) return a * b % m;
  return (i64)((i128)a * b % m);
}
i64 power(i64 b, i64 e, i64 m) {
  i64 r = 1 % m; b %= m; if (b < 0) b += m;
  for (; e > 0; e >>= 1, b = mulmod(b, b, m)) if (e & 1) r = mulmod(r, b, m);
  return r;
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
using Mint = ModInt<1'000'000'007>;
using Mint1 = ModInt<998'244'353>;

/********************************************************/

static const int _fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

/********************************************************/

class Solution {
  public:
  int totalSteps(vector<int>& a) {
    int n = sz(a), res = 0;
    vi st, dp(n, 0);

    fr(i, n - 1, 0) {
      while (!st.empty() && a[st.back()] < a[i]) {
        dp[i] = max(++dp[i], dp[st.back()]);
        st.pop_back();
        smax<int>(res, dp[i]);
      }
      st.pb(i);
    }

    return res;
  }
};
