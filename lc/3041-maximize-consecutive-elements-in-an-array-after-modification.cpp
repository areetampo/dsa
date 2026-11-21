#define DEBUG_MODE 1
#if !DEBUG_MODE
#define NDEBUG
#endif

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
  size_t operator()(const string& s) const {
    static const u64 R = chrono::steady_clock::now().time_since_epoch().count();
    u64 h = R;
    for (unsigned char c : s) h = sm(h + c);
    return h;
  }
  template <class... A> size_t operator()(const tuple<A...>& t) const {
    u64 h = 0;
    apply([&] (const auto&... e) { ((h = sm(h * 31 + (*this)(e))), ...); }, t);
    return h;
  }
  template <class T> size_t operator()(const vector<T>& v) const {
    u64 h = v.size();
    for (const auto& e : v) h = sm(h * 31 + (*this)(e));
    return h;
  }
  template <class T, size_t N> size_t operator()(const array<T, N>& v) const {
    u64 h = N;
    for (const auto& e : v) h = sm(h * 31 + (*this)(e));
    return h;
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
constexpr int dir8[9] = { 1, 1, 0, -1, -1, 1, -1, 0, 1 };
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
template <class A, class B, class C> inline bool inside(A x, B lo, C hi) { return lo <= x && x <= hi; }
template <class C> inline i64 argmin(const C& c) { return min_element(c.begin(), c.end()) - c.begin(); }
template <class C> inline i64 argmax(const C& c) { return max_element(c.begin(), c.end()) - c.begin(); }

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
#define REP_(n, id) for (i64 _r##id = 0; _r##id < (n); ++_r##id)
#define REP(n, id) REP_(n, id)
#define rep(n) REP(n, __COUNTER__)
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
#define DOUT cout // stream the debug prints go to: cerr/cout
// dbg(a, b) prints "a = .., b = .." for pretty much anything: containers, pairs, tuples, nested stuff, enums, optional
// a pointer prints what it points to (&5, null for nullptr) but only one level deep: any pointer inside that is just "ptr"
// so a list/tree node prints as {val = 5, left = ptr, right = null} instead of dumping everything behind it
// dbgf(x) is the "full" version: for a list node pointer it prints 1 -> 2 -> 3 -> null, for a tree node pointer the level order [1, 2, 3, null, 4]
// (also works on a vector / map of such pointers). cycles are cut instead of looping
// plain structs print their fields as {1, 2, 3}. if a struct has members that are arrays, or has a constructor, put DBG_FIELDS(x, y) inside it to get {x = 1, y = 2}
// stack, queue, deque, pq all print left to right starting from the end you take from (top / front)
// assert_eq(x, y) aborts and shows both values when they differ, for checking against a brute force
// sl / bl print a short / long dashed line
#if DEBUG_MODE
#define DBG_FIELDS(...) auto _dbg_fields() const { return make_pair(string(#__VA_ARGS__), tie(__VA_ARGS__)); }
template <class T> struct is_pair : false_type {};
template <class A, class B> struct is_pair<pair<A, B>> : true_type {};
template <class T> struct is_tuple : false_type {};
template <class... A> struct is_tuple<tuple<A...>> : true_type {};
template <class T> struct is_adapter : false_type {};
template <class T, class C> struct is_adapter<stack<T, C>> : true_type {};
template <class T, class C> struct is_adapter<queue<T, C>> : true_type {};
template <class T, class C, class P> struct is_adapter<priority_queue<T, C, P>> : true_type {};
template <class T> struct is_smart : false_type {};
template <class T> struct is_smart<shared_ptr<T>> : true_type {};
template <class T, class D> struct is_smart<unique_ptr<T, D>> : true_type {};
template <class T> struct is_opt : false_type {};
template <class T> struct is_opt<optional<T>> : true_type {};
template <class T, class = void> struct is_iter : false_type {};
template <class T> struct is_iter<T, void_t<decltype(begin(declval<T&>())), decltype(end(declval<T&>()))>> : true_type {};
template <class T, class = void> struct is_streamable : false_type {};
template <class T> struct is_streamable<T, void_t<decltype(declval<ostream&>() << declval<const T&>())>> : true_type {};
// anything with val + next counts as a list node, val + left + right as a tree node
template <class T, class = void> struct has_next : false_type {};
template <class T> struct has_next<T, void_t<decltype(declval<T&>().val), decltype(declval<T&>().next)>> : true_type {};
template <class T, class = void> struct has_lr : false_type {};
template <class T> struct has_lr<T, void_t<decltype(declval<T&>().val), decltype(declval<T&>().left), decltype(declval<T&>().right)>> : true_type {};
template <class T, class = void> struct has_fields : false_type {};
template <class T> struct has_fields<T, void_t<decltype(declval<const T&>()._dbg_fields())>> : true_type {};

// counts the members of a plain struct by checking how many initialisers it accepts (up to 10)
struct _any { template <class U> constexpr operator U() const; };
template <class T, size_t... I> auto _brace(index_sequence<I...>) -> decltype(T{ (void(I), _any{})... }, true_type{});
template <class T, size_t N, class = void> struct _brace_ok : false_type {};
template <class T, size_t N> struct _brace_ok < T, N, void_t<decltype(_brace<T>(make_index_sequence<N>{})) >> : true_type {};
template <class T, size_t N = 1> constexpr size_t _nf() {
  if constexpr (N > 11 || !_brace_ok<T, N>::value) return N - 1; else return _nf<T, N + 1>();
}
template <class T> auto _as_tuple(const T& x) {
  constexpr size_t N = _nf<T>();
  if constexpr (N == 1) { const auto& [a] = x; return tie(a); } else if constexpr (N == 2) { const auto& [a, b] = x; return tie(a, b); } else if constexpr (N == 3) { const auto& [a, b, c] = x; return tie(a, b, c); } else if constexpr (N == 4) { const auto& [a, b, c, d] = x; return tie(a, b, c, d); } else if constexpr (N == 5) { const auto& [a, b, c, d, e] = x; return tie(a, b, c, d, e); } else if constexpr (N == 6) { const auto& [a, b, c, d, e, f] = x; return tie(a, b, c, d, e, f); } else if constexpr (N == 7) { const auto& [a, b, c, d, e, f, g] = x; return tie(a, b, c, d, e, f, g); } else if constexpr (N == 8) { const auto& [a, b, c, d, e, f, g, h] = x; return tie(a, b, c, d, e, f, g, h); } else if constexpr (N == 9) { const auto& [a, b, c, d, e, f, g, h, i] = x; return tie(a, b, c, d, e, f, g, h, i); } else { const auto& [a, b, c, d, e, f, g, h, i, j] = x; return tie(a, b, c, d, e, f, g, h, i, j); }
}

template <class T, class C> T _top(const stack<T, C>& s) { return s.top(); }
template <class T, class C> T _top(const queue<T, C>& s) { return s.front(); }
template <class T, class C, class P> T _top(const priority_queue<T, C, P>& s) { return s.top(); }

template <class T> void _print(const T& x);
inline vector<string> _dbg_split(const string& s);
inline int& _pd() { static int d = 0; return d; }   // > 0 while we're inside a struct / pointee, pointers met there print as "ptr"
struct _Dg { _Dg() { _pd()++; } ~_Dg() { _pd()--; } };

template <class N> void _print_list(const N* p) {
  unordered_map<const N*, int> seen; int idx = 0;
  while (p) {
    if (seen.count(p)) { DOUT << "(back to #" << seen[p] << ")"; return; }
    seen[p] = idx++;
    _print(p->val); DOUT << " -> ";
    p = p->next;
  }
  DOUT << "null";
}
template <class N> void _print_tree(const N* root) {
  if (!root) { DOUT << "null"; return; }
  vector<const N*> v{ root }; unordered_set<const N*> seen{ root };
  for (size_t i = 0; i < v.size(); i++) if (v[i]) {
    for (const N* c : { (const N*)v[i]->left, (const N*)v[i]->right }) {
      if (c && seen.count(c)) c = nullptr;   // shared / looped child, don't follow it again
      if (c) seen.insert(c);
      v.push_back(c);
    }
  }
  while (!v.empty() && !v.back()) v.pop_back();
  DOUT << "[";
  for (size_t i = 0; i < v.size(); i++) { if (i) DOUT << ", "; if (v[i]) _print(v[i]->val); else DOUT << "null"; }
  DOUT << "]";
}

template <class N> void _print_node(const N& n) {
  _Dg g;
  DOUT << "{val = "; _print(n.val);
  if constexpr (has_next<N>::value) { DOUT << ", next = "; _print(n.next); } else { DOUT << ", left = "; _print(n.left); DOUT << ", right = "; _print(n.right); }
  DOUT << "}";
}

template <class T> void _print(const T& x) {
  if constexpr (is_same_v<T, string> || is_same_v<T, string_view>) DOUT << '"' << x << '"';
  else if constexpr (is_same_v<T, char>) DOUT << '\'' << x << '\'';
  else if constexpr (is_same_v<T, bool>) DOUT << (x ? "true" : "false");
  else if constexpr (is_enum_v<T>) DOUT << (i64)static_cast<underlying_type_t<T>>(x);
#ifdef __SIZEOF_INT128__
  else if constexpr (is_same_v<T, i128> || is_same_v<T, u128>) {   // cerr can't print these directly
    if (x == 0) { DOUT << 0; return; }
    string s; T y = x; bool neg = false;
    if constexpr (is_same_v<T, i128>) if (y < 0) { neg = true; y = -y; }
    while (y > 0) { s += char('0' + (int)(y % 10)); y /= 10; }
    if (neg) s += '-';
    reverse(s.begin(), s.end()); DOUT << s;
  }
#endif
  else if constexpr (is_pair<T>::value) {
    DOUT << "{"; _print(x.first); DOUT << ", "; _print(x.second); DOUT << "}";
  } else if constexpr (is_tuple<T>::value) {
    DOUT << "{";
    apply([] (const auto&... e) { size_t i = 0; ((DOUT << (i++ ? ", " : ""), _print(e)), ...); }, x);
    DOUT << "}";
  } else if constexpr (is_smart<T>::value) {
    _print(x.get());
  } else if constexpr (is_opt<T>::value) {
    if (x) _print(*x); else DOUT << "null";
  } else if constexpr (is_pointer_v<T>) {
    using E = remove_cv_t<remove_pointer_t<T>>;
    if (!x) DOUT << "null";
    else if constexpr (is_same_v<E, char>) DOUT << '"' << x << '"';
    else if constexpr (is_void_v<E>) DOUT << "ptr";
    else if constexpr (is_function_v<E>) DOUT << "<fn>";
    else if (_pd() > 0) DOUT << "ptr";
    else {
      _Dg g;
      if constexpr (!(has_next<E>::value || has_lr<E>::value)) DOUT << "&";   // nodes print bare, everything else gets a leading &
      _print(*x);
    }
  } else if constexpr (has_fields<T>::value) {
    _Dg g;
    auto nt = x._dbg_fields();
    auto names = _dbg_split(nt.first); size_t i = 0;
    DOUT << "{";
    apply([&] (const auto&... e) { ((DOUT << (i ? ", " : "") << names[i] << " = ", _print(e), ++i), ...); }, nt.second);
    DOUT << "}";
  } else if constexpr (has_next<T>::value || has_lr<T>::value) {
    _print_node(x);
  } else if constexpr (is_adapter<T>::value) {
    T c = x; vector<decay_t<decltype(_top(c))>> v;   // work on a copy and pop it dry
    while (!c.empty()) { v.push_back(_top(c)); c.pop(); }
    _print(v);
  } else if constexpr (is_iter<T>::value) {
    DOUT << "["; bool first = true;
    for (const auto& e : x) { if (!first) DOUT << ", "; first = false; _print(e); }
    DOUT << "]";
  } else if constexpr (is_streamable<T>::value) {
    DOUT << x;
  } else if constexpr (is_aggregate_v<T> && _nf<T>() >= 1 && _nf<T>() <= 10) {
    _Dg g;
    auto t = _as_tuple(x);
    DOUT << "{";
    apply([] (const auto&... e) { size_t i = 0; ((DOUT << (i++ ? ", " : ""), _print(e)), ...); }, t);
    DOUT << "}";
  } else DOUT << "<?>";
}

// full structure for list / tree node pointers (or a vector / map / pair of them), anything else prints as usual
template <class T> void _whole(const T& x) {
  if constexpr (is_pointer_v<T>) {
    using E = remove_cv_t<remove_pointer_t<T>>;
    if constexpr (has_next<E>::value) _print_list(x);
    else if constexpr (has_lr<E>::value) _print_tree(x);
    else _print(x);
  } else if constexpr (is_smart<T>::value) {
    _whole(x.get());
  } else if constexpr (is_pair<T>::value) {
    DOUT << "{"; _whole(x.first); DOUT << ", "; _whole(x.second); DOUT << "}";
  } else if constexpr (is_iter<T>::value && !is_same_v<T, string> && !is_same_v<T, string_view>) {
    DOUT << "["; bool first = true;
    for (const auto& e : x) { if (!first) DOUT << ", "; first = false; _whole(e); }
    DOUT << "]";
  } else _print(x);
}

// splits "a, f(x, y), v" on top level commas only, so the names line up with the values
inline vector<string> _dbg_split(const string& s) {
  vector<string> res; string cur; int depth = 0;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;
    if (c == ',' && depth == 0) { res.push_back(cur); cur.clear(); } else cur += c;
  }
  res.push_back(cur);
  for (auto& t : res) {
    size_t a = t.find_first_not_of(" \t"), b = t.find_last_not_of(" \t");
    t = (a == string::npos) ? "" : t.substr(a, b - a + 1);
  }
  return res;
}
template <class... A> void _dbg_impl(const vector<string>& names, const A&... a) {
  size_t i = 0;
  ((DOUT << names[i++] << " = ", _print(a), DOUT << (i < sizeof...(A) ? ", " : "\n")), ...);
}
template <class... A> void _dbgf_impl(const vector<string>& names, const A&... a) {
  size_t i = 0;
  ((DOUT << names[i++] << " = ", _whole(a), DOUT << (i < sizeof...(A) ? ", " : "\n")), ...);
}
#define dbg(...) do { auto _n = _dbg_split(#__VA_ARGS__); _dbg_impl(_n, __VA_ARGS__); } while (0)
#define dbgf(...) do { auto _n = _dbg_split(#__VA_ARGS__); _dbgf_impl(_n, __VA_ARGS__); } while (0)
#define assert_eq(a, b) do { auto _x = (a); auto _y = (b); if (!(_x == _y)) { \
    DOUT << "mismatch: "; _print(_x); DOUT << " vs "; _print(_y); DOUT << endl; abort(); } } while (0)
inline void dsep(int n = 40) { DOUT << string(n, '-') << "\n"; }
#define sl dsep(20)
#define bl dsep(40)
#else
#define DBG_FIELDS(...)
#define dbg(...) ((void)0)
#define dbgf(...) ((void)0)
#define assert_eq(a, b) ((void)0)
inline void dsep(int = 40) {}
#define sl
#define bl
#endif

/********************************************************/
/* ListNode / TreeNode                                  */
/********************************************************/
#if defined(LOCAL) || defined(__INTELLISENSE__)
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

// INT_MIN marks a missing child (change with the second argument) | freeTree(root) -> delete the tree
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
  constexpr ModInt(i64 x = 0) : v((u32)((x %= (i64)M) < 0 ? x + M : x)) {}
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
 * CORE IDEA
 * ---------
 * Each element x can end up as either x or x+1 (raised by at most 1).
 * We want the longest run of consecutive values we can cover, where each
 * element fills at most one value.
 *
 * dp[v] = length of the longest consecutive run ending exactly at value v,
 *         using only the elements processed so far.
 *
 * Process values in increasing order. For each element with value v there
 * are two choices:
 *   1. Raise it to v+1: it extends a run ending at v   -> dp[v+1] = dp[v] + 1
 *   2. Keep it at v:    it extends a run ending at v-1 -> dp[v]   = dp[v-1] + 1
 * The "+1" is this element joining the run. If no run ends at the previous
 * value, dp is 0 and the run is just this element (length 1), so no base-case
 * initialisation is needed.
 *
 * WHY dp[v+1] IS UPDATED BEFORE dp[v]
 * -----------------------------------
 * The shift line READS dp[v], and the stay line WRITES dp[v]. If we wrote
 * dp[v] first, the shift would see a run that already contains this same
 * element and count it twice (e.g. [1] would wrongly give {1,2}, length 2).
 * Updating dp[v+1] first makes both choices read the state from before this
 * element was processed.
 *
 * DUPLICATES
 * ----------
 * A second copy of v reads the dp[v] left by the first copy. That is valid:
 * one copy stays at v and the other becomes v+1, so duplicates chain
 * naturally. A third copy adds nothing new (only v and v+1 are reachable),
 * so at most 2 copies per value are processed.
 *
 * COMPLEXITY
 * ----------
 * Using a frequency table instead of sorting: O(maxValue + n) time,
 * O(maxValue) space. Values can reach 1e6 + 1 after the raise.
 */
class Solution {
  public:
  int maxSelectedElements(vector<int>& a) {
    const int M = *max_element(all(a)) + 2;
    vector<int> cnt(M + 2, 0), dp(M + 2, 0);
    trav(i, a) cnt[i]++;

    int res = 1;
    fo(v, 1, M + 1) {
      fo(c, 0, min(cnt[v], 2)) {
        dp[v + 1] = dp[v] + 1; // this copy becomes v+1
        dp[v] = dp[v - 1] + 1; // this copy stays v
        smax(res, max(dp[v], dp[v + 1]));
      }
    }

    return res;
  }
};
