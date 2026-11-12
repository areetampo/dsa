// ============================================================
// Paste everything above "class Solution" into the TOP of the
// LeetCode editor. If LeetCode already gave you a ListNode /
// TreeNode struct, keep that where it is (right before your
// class Solution) — don't move it above this prelude.
// No main()/precomp()/solve() — LeetCode supplies its own driver
// and calls your Solution method directly.
// Recommended: set the language dropdown to C++17 or later.
// ============================================================
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
using vvi = vector<vi>;
using pi = pair<i64, i64>;
using ti = tuple<i64, i64, i64>;
using vpi = vector<pi>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> void smin(T& a, const T& b) { if (a > b) a = b; }
template <typename T> void smax(T& a, const T& b) { if (a < b) a = b; }
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int imax = numeric_limits<int>::max(), imin = numeric_limits<int>::min();
const i64 lmax = numeric_limits<i64>::max(), lmin = numeric_limits<i64>::min();
const i64 INF = 1e18; // safe "infinity" sentinel — leaves headroom so INF + x doesn't overflow like lmax + x would
const i64 mod = 1000000007, mod1 = 998244353;
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

/********************************************************/
/* Debug print — set DEBUG_MODE to 0 to silence, no code */
/* changes needed elsewhere. Uses cout (not cerr) since   */
/* LeetCode's "Run Code" console reliably shows stdout    */
/* but not always stderr.                                 */
/********************************************************/
#define DEBUG_MODE 1

template<typename T>
void _print(T t) { cout << t; }
template<typename T, typename... Args>
void _print(T t, Args... args) { cout << t << " "; _print(args...); }
template<class T, class V> void _print(pair<T, V> p) { cout << "{"; _print(p.ff); cout << " "; _print(p.ss); cout << "}"; }
template<class T, class V, class W> void _print(tuple<T, V, W> t) { cout << "{"; _print(get<0>(t)); cout << " "; _print(get<1>(t)); cout << " "; _print(get<2>(t)); cout << "}"; }
template<class T> void _print(vector<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(vector<vector<T>> v) { trav(i, v) { cout << "\n"; _print(i); } }
template<class T> void _print(set<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(multiset<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(unordered_set<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T, class V> void _print(map<T, V> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(queue<T> q) { vector<T> t; cout << "[ "; while (!q.empty()) { _print(q.front()); cout << " "; t.pb(q.front()); q.pop(); } cout << "]"; trav(i, t) q.push(i); }
template<class T> void _print(pq<T> pqq) { vector<T> t; cout << "[ "; while (!pqq.empty()) { _print(pqq.top()); cout << " "; t.pb(pqq.top()); pqq.pop(); } cout << "]"; trav(i, t) pqq.push(i); }
template<class T> void _print(pqg<T> pqq) { vector<T> t; cout << "[ "; while (!pqq.empty()) { _print(pqq.top()); cout << " "; t.pb(pqq.top()); pqq.pop(); } cout << "]"; trav(i, t) pqq.push(i); }
inline void small_line() { cout << string(20, '-') << "\n"; }
inline void big_line() { cout << string(40, '-') << "\n"; }

// dbg(a, b, c, ...) — prints one "name = value" per line to cout (LeetCode's
// "Run Code" console reliably shows stdout but not always stderr). Works with
// any number of args; each value goes through _print above, so containers
// print with their own brackets — no extra wrapper around the name itself.
//
// Custom names: wrap any single arg as nm("label", expr) to override the
// auto-derived label — e.g. dbg(nm("x half", x/2)) prints "x half = <val>"
// instead of "x/2 = <val>". Mix freely with plain args: dbg(n, nm("x half", x/2), v).
#if DEBUG_MODE
inline vector<string> _dbg_split(const string& s) {
  vector<string> res; string cur; int depth = 0;
  for (char c : s) {
    if (c == '(' || c == '[' || c == '{') depth++;
    if (c == ')' || c == ']' || c == '}') depth--;
    if (c == ',' && depth == 0) { res.pb(cur); cur.clear(); } else cur += c;
  }
  res.pb(cur);
  for (auto& t : res) {
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
void _dbg_one(const string& fallback, const T& x) { cout << fallback << " = "; _print(x); }
template<typename T>
void _dbg_one(const string& fallback, const _DbgNamed<T>& x) { (void)fallback; cout << x.name << " = "; _print(x.value); }

inline void _dbg_print_all(vector<string>::iterator) {}
template<typename T, typename... Args>
void _dbg_print_all(vector<string>::iterator it, T&& first, Args&&... rest) {
  _dbg_one(*it, first); cout << "\n";
  _dbg_print_all(++it, rest...);
}
#define dbg(...) do { auto _dbg_names = _dbg_split(#__VA_ARGS__); _dbg_print_all(_dbg_names.begin(), __VA_ARGS__); } while(0)
#else
#define dbg(...)
#endif
// dbg works on scalars AND containers (vector/set/map/pair/tuple3/queue/pq)
// via the _print overloads above — e.g. dbg(nums); dbg(freq_map); dbg(dp[i][j]);

/********************************************************/
/* Generic list / tree helpers                           */
/* These are templates, so they compile fine even though */
/* ListNode/TreeNode aren't declared yet in this file —   */
/* the compiler only checks the Node->val / Node->next /  */
/* Node->left / Node->right usage once you actually call  */
/* these AFTER LeetCode's own struct definitions appear.   */
/********************************************************/
template<class Node>
void printList(Node* head) {
  cout << "[ ";
  while (head) { cout << head->val << " "; head = head->next; }
  cout << "]\n";
}
template<class Node>
Node* buildList(const vi& v) {
  Node dummy(0); Node* cur = &dummy;
  for (auto x : v) { cur->next = new Node(x); cur = cur->next; }
  return dummy.next;
}
// Simple indented preorder print (val, then left subtree, then right subtree)
template<class Node>
void printTree(Node* root, int depth = 0) {
  if (!root) { cout << string(depth * 2, ' ') << "null\n"; return; }
  cout << string(depth * 2, ' ') << root->val << "\n";
  if (root->left || root->right) {
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
  }
}

/********************************************************/
/* Math                                                 */
/********************************************************/
inline i64 mulmod(i64 a, i64 b, i64 m) {
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
i64 inv(i64 a, i64 m = mod) { return power(a, m - 2, m); } // needs m prime, gcd(a,m)=1
i64 madd(i64 a, i64 b, i64 m = mod) { return (a + b) % m; }
i64 msub(i64 a, i64 b, i64 m = mod) { return ((a - b) % m + m) % m; }
i64 mmul(i64 a, i64 b, i64 m = mod) { return mulmod(a, b, m); }
i64 mdiv(i64 a, i64 b, i64 m = mod) { return mulmod(a % m, inv(b, m), m); }

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
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

/********************************************************/
/* Combinatorics — call precomp_factorials() once before use   */
/* (LeetCode inputs are usually small, so MAXN is trimmed down  */
/* from the 2e6 CP default — bump it if a problem needs more)   */
/********************************************************/
const int MAXN = 2e5 + 5;
i64 fact[MAXN], inv_fact[MAXN];
void precomp_factorials() {
  fact[0] = 1;
  fo(i, 1, MAXN) fact[i] = fact[i - 1] * i % mod;
  inv_fact[MAXN - 1] = inv(fact[MAXN - 1]);
  fr(i, MAXN - 2, 0) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}
i64 C(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] % mod * inv_fact[r] % mod * inv_fact[n - r] % mod;
}
i64 P(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] % mod * inv_fact[n - r] % mod;
}

/********************************************************/
/* Sieve                                                 */
/********************************************************/
vector<bool> is_prime;
void sieve(int n = MAXN) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; (i64)i * i <= n; i++)
    if (is_prime[i])
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
}
vector<int> spf;
void sieve_spf(int n = MAXN) {
  spf.resize(n + 1);
  iota(spf.begin(), spf.end(), 0);
  for (int i = 2; (i64)i * i <= n; i++)
    if (spf[i] == i)
      for (int j = i * i; j <= n; j += i)
        if (spf[j] == j) spf[j] = i;
}
vi factorize(i64 x) {
  vi factors;
  while (x > 1) { factors.pb(spf[x]); x /= spf[x]; }
  return factors;
}

/********************************************************/
/* DSU (Union-Find)                                      */
/********************************************************/
struct DSU {
  vi par, sz;
  DSU(i64 n) : par(n), sz(n, 1) { iota(all(par), 0); }
  i64 find(i64 x) { return par[x] == x ? x : par[x] = find(par[x]); }
  bool unite(i64 a, i64 b) {
    a = find(a); b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
    return true;
  }
  bool same(i64 a, i64 b) { return find(a) == find(b); }
};

/********************************************************/
/* OPTIONAL: auto-run precomp once before any test case, */
/* mimicking the CP template's `precomp()` call in main. */
/* Delete this block if you don't need factorials/sieve. */
/********************************************************/
// struct _Init { _Init() { precomp_factorials(); /* sieve(); sieve_spf(); */ } } _init;

// ============================================================
// Paste stops here. Below is where LeetCode's own ListNode /
// TreeNode structs (if the problem uses them) and class
// Solution go. Example usage shown below.
// ============================================================
class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        vector<pair<int, int>> seg(26, {-1, -1}); // first, last occurence
        for (int i = 0; i < s.size(); i++) {
            if (seg[s[i] - 97].first == -1) seg[s[i] - 97].first = i;
            seg[s[i] - 97].second = i;
        }
        // 1 <= k <= 26
        // at max 26 disjoint segments possible
        // find valid intervals
        dbg(seg);
        vector<pair<int, int>> iv;
        for (int i = 0; i < 26; i++) {
            auto [l, r] = seg[i];
            if (l == -1) continue;
            bool taken = 0;
            for (int j = l; j <= r; j++) {
                if (seg[s[j] - 97].first < l) { taken = 1; break; }
                if (s[j] != i + 97) smax(r, seg[s[j] - 97].second);
            }
            if (taken) continue;
            iv.pb({l, r});
        }
        // find disjoints
        sort(all(iv), [](const auto& a, const auto& b){
            return a.second != b.second ? a.second < b.second : a.first < b.first; 
        });
        dbg(iv);
        int cnt = 0, last_r = -1;
        for (auto& i : iv) {
            auto [l, r] = i;
            if (l >= last_r) {
                cnt++;
                last_r = r;
            }
        }
        // note substring isnt the entire string
        return k == 1 ? iv.size() > 1 : k <= cnt;
    }
};