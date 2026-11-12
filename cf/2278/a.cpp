#pragma GCC optimize("O3,unroll-loops")

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

/********************************************************/
/* Utility Functions & Constants                        */
/********************************************************/
template <typename T> inline bool smin(T& a, const T& b) { return b < a ? a = b, true : false; }
template <typename T> inline bool smax(T& a, const T& b) { return a < b ? a = b, true : false; }

constexpr int dir[5] = { 1, 0, -1, 0, 1 };
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
inline i64 rnd(i64 lo, i64 hi) { return uniform_int_distribution<i64>(lo, hi)(rng); }

constexpr int FP_PREC = 15;
template <typename T>
void print_fp(T x, int precision = FP_PREC) {
  cout << fixed << setprecision(precision) << x << '\n';
}

/********************************************************/
/* Macros & Iteration Helpers                           */
/********************************************************/
#define fo(i, x, y, ...) for (i64 i = (x); i < (y); i += (0 __VA_ARGS__ + 1))
#define fr(i, x, y, ...) for (i64 i = (x); i >= (y); i -= (0 __VA_ARGS__ + 1))
#define fox(i, x, y, expr) for (i64 i = (x); i < (y); i = (expr))
#define frx(i, x, y, expr) for (i64 i = (x); i >= (y); i = (expr))
#define trav(a, b) for(auto& a: b)
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
#define YES cout << "YES\n"
#define NO cout << "NO\n"

/********************************************************/
/* Debug System Setup (Uses cerr)                       */
/********************************************************/
#define DEBUG_MODE 1

#if DEBUG_MODE
#define sl cerr << string(20, '-') << "\n"
#define bl cerr << string(40, '-') << "\n"
#else
#define sl
#define bl
#endif

template<typename T> void _print(T t) { cerr << t; }
template<typename T, typename... Args> void _print(T t, Args... args) { cerr << t << " "; _print(args...); }
template<class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << " "; _print(p.ss); cerr << "}"; }

template<class Tuple, size_t... Is>
void _print_tuple_impl(const Tuple& t, index_sequence<Is...>) {
  cerr << "{";
  size_t idx = 0;
  ((cerr << (idx++ ? " " : ""), _print(get<Is>(t))), ...);
  cerr << "}";
}
template<class... Args> void _print(const tuple<Args...>& t) {
  _print_tuple_impl(t, index_sequence_for<Args...>{});
}

template<class T> void _print(vector<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
inline void _print(const vector<bool>& v) { cerr << "[ "; for (bool b : v) cerr << b << " "; cerr << "]"; }
template<class T, size_t N> void _print(const T(&arr)[N]) { cerr << "[ "; fo(idx, 0, (int)N) { _print(arr[idx]); cerr << " "; } cerr << "]"; }
template<class T, size_t N> void _print(const array<T, N>& arr) { cerr << "[ "; trav(i, arr) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(vector<vector<T>> v) { trav(i, v) { cerr << "\n"; _print(i); } }
template<class T> void _print(stack<T> s) { vector<T> t; while (!s.empty()) { t.pb(s.top()); s.pop(); } cerr << "[ "; while (!t.empty()) { _print(t.back()); cerr << " "; s.push(t.back()); t.pop_back(); } cerr << "]"; }
template<class T> void _print(queue<T> q) { vector<T> t; cerr << "[ "; while (!q.empty()) { _print(q.front()); cerr << " "; t.pb(q.front()); q.pop(); } cerr << "]"; trav(i, t) q.push(i); }
template <class T> void _print(deque<T>& dq) { cerr << "[ "; fo(i, 0, sz(dq)) { _print(dq.front()); cerr << " "; dq.pb(dq.front()); dq.pop_front(); } cerr << "]"; }
template<class T> void _print(pq<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(pqg<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(set<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(unordered_set<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }

#if DEBUG_MODE
inline vector<string> _dbg_split(const string& s) {
  vector<string> res; string cur; int depth = 0;
  trav(c, s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;
    if (c == ',' && depth == 0) { res.pb(cur); cur.clear(); } else cur += c;
  }
  res.pb(cur);
  trav(t, res) {
    size_t a = t.find_first_not_of(" \t");
    size_t b = t.find_last_not_of(" \t");
    t = (a == string::npos) ? "" : t.substr(a, b - a + 1);
  }
  return res;
}

template<typename T> struct _DbgNamed { const char* name; T value; };
template<typename T> _DbgNamed<T> nm(const char* name, T value) { return _DbgNamed<T>{name, value}; }

template<typename T> void _dbg_one(const string& fallback, const T& x) { cerr << fallback << " = "; _print(x); }
template<typename T> void _dbg_one(const string& fallback, const _DbgNamed<T>& x) { (void)fallback; cerr << x.name << " = "; _print(x.value); }

inline void _dbg_print_all(vector<string>::iterator) { cerr << "\n"; }
template<typename T, typename... Args>
void _dbg_print_all(vector<string>::iterator it, T&& first, Args&&... rest) {
  _dbg_one(*it, first);
  if (sizeof...(rest) > 0) cerr << ", ";
  _dbg_print_all(++it, rest...);
}
#define dbg(...) do { auto _dbg_names = _dbg_split(#__VA_ARGS__); _dbg_print_all(_dbg_names.begin(), __VA_ARGS__); } while(0)
#else
#define dbg(...)
#endif

/********************************************************/
/* Input Helpers                                        */
/********************************************************/
template <class T = i64> vector<T> iv(i64 n) { vector<T> v(n); fo(i, 0, n) cin >> v[i]; return v; }
template <class T = i64> vector<vector<T>> im(i64 n, i64 m) { vector<vector<T>> v; fo(i, 0, n) v.pb(iv<T>(m)); return v; }
template <class T = i64, class S = i64> vector<pair<T, S>> ip(i64 n) { vector<pair<T, S>> v(n); fo(i, 0, n) { cin >> v[i].ff >> v[i].ss; } return v; }

auto ig(i64 n, i64 m, bool undirected = true) {
  vvi adj(n + 1);
  fo(i, 0, m) {
    i64 u, v; cin >> u >> v;
    adj[u].pb(v);
    if (undirected) adj[v].pb(u);
  }
  return adj;
}

/********************************************************/
/* Math Functions                                       */
/********************************************************/
inline i64 mulmod(i64 a, i64 b, i64 m = mod) {
#if defined(__SIZEOF_INT128__)
  return (__int128)a * b % m;
#else
  i64 res = 0; a %= m;
  while (b > 0) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
#endif
}

i64 power(i64 base, i64 exp, i64 m = mod) {
  i64 res = 1; base %= m;
  while (exp > 0) {
    if (exp & 1) res = mulmod(res, base, m);
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
  if (n < 0) return -1;
  if (n == 0) return 0;
  i64 r = (i64)sqrtl((f80)n);
  while (r > 0 && r > n / r) r--;
  while ((r + 1) <= n / (r + 1)) r++;
  return r;
}

template<typename T> T sign(T x) { return (x > 0) - (x < 0); }
template<class T> i32 sz(const T& c) { return static_cast<i32>(c.size()); }

/********************************************************/
/* Program Entry Point                                  */
/********************************************************/
i32 TC_TOTAL = 1, TC_CUR = 0;


inline void precomp() {
  // swap_mod();
}

inline void solve() {
  int n, d; string sn, sd; cin >> n >> d >> sn >> sd;
  vi c(26, 0);
  trav(i, sn) c[i - 'a']++;
  trav(i, sd) c[i - 'a']--;
  fo(i, 0, 26) {
    if (c[i] != (i == 's' - 'a' || i == 'i' - 'a' || i == 'x' - 'a')) {
      no; return;
    }
  }
  yes;
}

i32 main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if DEBUG_MODE
  auto begin = chrono::steady_clock::now();
#endif

  precomp();
  bl;

  cin >> TC_TOTAL;
  for (TC_CUR = 1; TC_CUR <= TC_TOTAL; TC_CUR++) {
    solve();
    bl;
  }

#if DEBUG_MODE
  auto end = chrono::steady_clock::now();
  cerr << "time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms\n";
  bl;
#endif

  return 0;
}
