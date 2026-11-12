#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double
#define f80 long double
using vi = vector<i64>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vi>;
using pi = pair<i64, i64>;
using ti = tuple<i64, i64, i64>;
using vpi = vector<pi>;
using mi = map<i64, i64>;
using si = set<i64>;
using um = unordered_map<i64, i64>;
using us = unordered_set<i64>;
template <class K, class V> using mp = map<K, V>;
template <class K, class V> using ump = unordered_map<K, V>;
template <class T> using st = set<T>;
template <class T> using ust = unordered_set<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> void smin(T& a, const T& b) { if (a > b) a = b; }
template <typename T> void smax(T& a, const T& b) { if (a < b) a = b; }
const int dir[5] = { 1,0,-1,0,1 };
const int imax = numeric_limits<int>::max(), imin = numeric_limits<int>::min();
const i64 lmax = numeric_limits<i64>::max(), lmin = numeric_limits<i64>::min();
const i64 INF = 1e18;
const i64 mod1 = 1000000007, mod2 = 998244353;
i64 mod = mod1;
inline void swap_mod() { mod = (mod == mod1) ? mod2 : mod1; }
#define fo(i, x, y) for (int i = x; i < y; i++)
#define foi(i, x, y, inc) for (int i = x; i < y; i += inc)
#define fr(i, x, y) for (int i = x; i >= y; i--)
#define frd(i, x, y, dec) for (int i = x; i >= y; i -= dec)
#define trav(a, b) for(auto& a: b)
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define alln(x, n) (x), (x) + (n)
#define yes cout << "Yes\n"
#define no cout << "No\n"

// Central debug toggle — also gates sl/bl below and dbg() further down.
// Flip to 0 before submitting to a judge if you want zero debug overhead.
#define DEBUG_MODE 1
#if DEBUG_MODE
#define sl cerr << string(20, '-') << "\n"
#define bl cerr << string(40, '-') << "\n"
#else
#define sl
#define bl
#endif

/********************************************************/
/* Debug print                                          */
/********************************************************/
template<typename T>
void _print(T t) { cerr << t; }
template<typename T, typename... Args>
void _print(T t, Args... args) { cerr << t << " "; _print(args...); }
template<class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << " "; _print(p.ss); cerr << "}"; }
template<class T, class V, class W> void _print(tuple<T, V, W> t) { cerr << "{"; _print(get<0>(t)); cerr << " "; _print(get<1>(t)); cerr << " "; _print(get<2>(t)); cerr << "}"; }
template<class T> void _print(vector<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
// vector<bool> is bit-packed — dereferencing its iterator gives a temporary
// proxy, not a real bool&, which trav()'s `auto&` can't bind to. Iterate by
// value instead; this exact overload wins over the generic vector<T> one.
inline void _print(const vector<bool>& v) { cerr << "[ "; for (bool b : v) cerr << b << " "; cerr << "]"; }
// Fixed-size C array, any dimension (int a[5], int a[3][4], ...). Binding by
// reference-to-array preserves the size and skips the pointer decay that
// would otherwise lose it; recurses cleanly since each row of a 2D array is
// itself a fixed-size array matching this same overload.
template<class T, size_t N> void _print(const T(&arr)[N]) { cerr << "[ "; fo(idx, 0, (int)N) { _print(arr[idx]); cerr << " "; } cerr << "]"; }
template<class T> void _print(vector<vector<T>> v) { trav(i, v) { cerr << "\n"; _print(i); } }
template<class T> void _print(queue<T> q) { vector<T> t; cerr << "[ "; while (!q.empty()) { _print(q.front()); cerr << " "; t.pb(q.front()); q.pop(); } cerr << "]"; trav(i, t) q.push(i); }
template<class T> void _print(pq<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(pqg<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(set<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(unordered_set<T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map<T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }

// dbg(a, b, c, ...) — prints "a = <val>, b = <val>, c = <val>" on one line to cerr.
// Works with any number of comma-separated args, and each value goes through
// the _print overloads above, so vectors/maps/sets/pairs/etc. print correctly
// too (not just scalars).
//
// Custom names: wrap any single arg as nm("label", expr) to override the
// auto-derived label — e.g. dbg(nm("x half", x/2)) prints "x half = <val>"
// instead of "x/2 = <val>". Mix freely with plain args: dbg(n, nm("x half", x/2), v).
//
// Gated by DEBUG_MODE above, rather than a -DLOCAL compiler flag, since most
// IDE "Run" buttons (VS Code, CLion, etc.) don't pass custom flags by default.
#if DEBUG_MODE
// Splits the raw "a, b, c" text of the macro args into individual trimmed
// names, respecting nested (), [], {} so commas inside e.g. make_pair(1,2)
// don't cause a wrong split.
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
// Wrapper for a custom-named debug value. Constructed via nm(...) below.
template<typename T> struct _DbgNamed { const char* name; T value; };
template<typename T> _DbgNamed<T> nm(const char* name, T value) { return _DbgNamed<T>{name, value}; }

// Overload resolution (not runtime type checks) picks the right one:
// exact match on _DbgNamed<T> wins over the generic template whenever the
// arg came from nm(...), so the stored custom name is used instead of the
// fallback text captured by _dbg_split.
template<typename T>
void _dbg_one(const string& fallback, const T& x) { cerr << fallback << " = "; _print(x); }
template<typename T>
void _dbg_one(const string& fallback, const _DbgNamed<T>& x) { (void)fallback; cerr << x.name << " = "; _print(x.value); }

// Prints all args comma-separated on one line, ending with a single newline.
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
/* Input helpers                                        */
/********************************************************/
template <class T = i64> vector<T> iv(i64 n) { vector<T> v(n); fo(i, 0, n) cin >> v[i]; return v; }
template <class T = i64> vector<vector<T>> im(i64 n, i64 m) { vector<vector<T>> v; fo(i, 0, n) v.pb(iv<T>(m)); return v; }
template <class T = i64, class S = i64> vector<pair<T, S>> ip(i64 n) { vector<pair<T, S>> v(n); fo(i, 0, n) { cin >> v[i].ff >> v[i].ss; } return v; }

// Read adjacency list — ig(n, m) for undirected, ig(n, m, false) for directed
auto ig(i64 n, i64 m, bool undirected = true) {
  vector<vi> adj(n + 1);
  fo(i, 0, m) {
    i64 u, v; cin >> u >> v;
    adj[u].pb(v);
    if (undirected) adj[v].pb(u);
  }
  return adj;
}

/********************************************************/
/* Math                                                 */
/********************************************************/
// Portable safe multiplication — uses __int128 on GCC/Clang, fallback on MSVC/MinGW
inline i64 mulmod(i64 a, i64 b, i64 m = mod) {
#if defined(__SIZEOF_INT128__)
  return (__int128)a * b % m;
#else
    // Russian peasant multiplication — O(log b), safe on all platforms
  i64 res = 0; a %= m;
  while (b > 0) {
    if (b & 1) res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
#endif
}

// Safe modular exponentiation
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

// Modular arithmetic helpers
i64 madd(i64 a, i64 b, i64 m = mod) { return (a + b) % m; }
i64 msub(i64 a, i64 b, i64 m = mod) { return ((a - b) % m + m) % m; }
i64 mmul(i64 a, i64 b, i64 m = mod) { return mulmod(a, b, m); }
// a / b (mod m) = a * b^-1 (mod m)
// NOTE: inv() uses Fermat's little theorem, so this is only correct when m is
// PRIME and gcd(b, m) == 1 (true for mod / mod1, false for an arbitrary m —
// use extended Euclidean / modular inverse via egcd there instead).
i64 mdiv(i64 a, i64 b, i64 m = mod) { return mulmod(a % m, inv(b, m), m); }

// GCD / LCM
// NOTE: these intentionally shadow std::gcd/std::lcm (from <numeric>, pulled in
// via bits/stdc++.h + `using namespace std;`). Non-template overloads win over
// the std:: function templates during overload resolution, so calls like
// gcd(a, b) with i64 args resolve here safely — no need to rename.
i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }

// Ceiling integer division
i64 ceil_div(i64 a, i64 b) { return (a + b - 1) / b; }

// Integer square root (largest x s.t. x*x <= n), works for the full i64 range
// and handles n = 0/1 correctly. Seeded with sqrtl then corrected with a
// couple of +-1 adjustment steps (float sqrt can be off by one at the edges).
i64 isqrt(i64 n) {
  if (n < 0) return -1;
  if (n == 0) return 0;
  i64 r = (i64)sqrtl((f80)n);
  while (r > 0 && r > n / r) r--;          // avoid overflow: r*r > n  <=>  r > n/r
  while ((r + 1) <= n / (r + 1)) r++;
  return r;
}

// Sign
template<typename T> T sign(T x) { return (x > 0) - (x < 0); }

// container.size() as i32 instead of size_t — avoids signed/unsigned comparison
// warnings when mixing with int loop counters, e.g. fo(i, 0, sz(v))
template<class T> i32 sz(const T& c) { return (i32)c.size(); }

/********************************************************/

// nCr/nPr — modular (mod p) and small-exact variants. Call
// precomp_factorials() once before using C()/P(); C_exact()/P_exact() are
// self-contained and don't need it.
//
// Complexity: precomp_factorials() is O(MAXN), one-time; C/P are O(1) each
// after that; C_exact/P_exact are O(r) each, no precomp needed.
//
// Usage:
//   precomp_factorials();
//   C(5, 2);           // 10, mod `mod` (the template's default 1e9+7)
//   P(5, 2);            // 20, mod `mod`
//   C_exact(10, 3);     // 120, exact (no mod), only safe for n <= ~60
//
// NOTE: MAXN is guarded with #ifndef so this can be safely pasted alongside
// sieve.cpp (which also defines MAXN) without a duplicate-definition error —
// whichever file gets pasted first "wins" and sets the shared value. Bump
// the number below if a problem needs a larger n than 2e6.
#ifndef MAXN
#define MAXN 2000005
#endif
i64 fact[MAXN], inv_fact[MAXN];
void precomp_factorials() {
  fact[0] = 1;
  fo(i, 1, MAXN) fact[i] = fact[i - 1] * i % mod;
  inv_fact[MAXN - 1] = inv(fact[MAXN - 1]);
  fr(i, MAXN - 2, 0) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

// nCr mod p — number of ways to choose r from n (requires precomp_factorials)
i64 C(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] % mod * inv_fact[r] % mod * inv_fact[n - r] % mod;
}

// nPr mod p — number of ways to arrange r from n (requires precomp_factorials)
// nPr = n! / (n-r)! = C(n,r) * r!
i64 P(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] % mod * inv_fact[n - r] % mod;
}

// nCr exact (no mod) — only safe for small n (n <= ~60); returns -1 on overflow
i64 C_exact(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  if (r > n - r) r = n - r;
  i64 res = 1;
  fo(i, 0, r) {
    if (res > (i64)9e18 / (n - i)) return -1;
    res = res * (n - i) / (i + 1);
  }
  return res;
}

// nPr exact (no mod) — only safe for very small n (n <= ~20); returns -1 on overflow
i64 P_exact(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  i64 res = 1;
  fo(i, 0, r) {
    if (res > (i64)9e18 / (n - i)) return -1;
    res *= (n - i);
  }
  return res;
}

inline void precomp() {
  // swap_mod();
  // precomp_factorials();
}
vvi g; string s;
vector<bool> vis;
int r;
pi dfs(int i) {
  vis[i] = 1;
  int b = s[i - 1] == 'B', w = s[i - 1] == 'W';
  trav(child, g[i]) {
    if (vis[child]) continue;
    auto [cb, cw] = dfs(child);
    b += cb, w += cw;
  }
  r += b == w;
  // dbg(i, b, w);
  return { b, w };
}
inline void solve() {
  int n; cin >> n;
  g = vvi(n + 1, vi());
  fo(i, 1, n) {
    int child = i + 1, par; cin >> par;
    g[par].pb(child);
  }
  cin >> s;

  vis = vector<bool>(n + 1, 0);
  r = 0;
  dfs(1);

  cout << r << "\n";

}

/********************************************************/
i32 main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  auto begin = chrono::steady_clock::now();
  precomp();
  bl;
  i32 t = 1;
  cin >> t;
  while (t--) {
    solve();
    bl;
  }
  auto end = chrono::steady_clock::now();
  cerr << "time: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms\n";
  bl;
  return 0;
}