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
const i64 INF = 1e18; // safe "infinity" sentinel — INF + x won't overflow like lmax + x would
const i64 mod = 1000000007, mod1 = 998244353;
#define fo(i, x, y) for (int i = x; i < y; i++)
#define foi(i, x, y, inc) for (int i = x; i < y; i += inc)
#define fr(i, x, y) for (int i = x; i >= y; i--)
#define frd(i, x, y, dec) for (int i = x; i >= y; i -= dec)
#define trav(a, b) for (auto& a: b)
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()

// Central debug toggle — also gates sl/bl below and dbg() further down.
// Uses cout, not cerr, since LeetCode's "Run Code" console reliably shows
// stdout but not always stderr. Flip to 0 to silence everything.
#define DEBUG_MODE 1
#if DEBUG_MODE
#define sl cout << string(20, '-') << "\n"
#define bl cout << string(40, '-') << "\n"
#else
#define sl
#define bl
#endif

/********************************************************/
/* Debug print                                          */
/********************************************************/
template<typename T>
void _print(T t) { cout << t; }
template<typename T, typename... Args>
void _print(T t, Args... args) { cout << t << " "; _print(args...); }
template<class T, class V> void _print(pair<T, V> p) { cout << "{"; _print(p.ff); cout << " "; _print(p.ss); cout << "}"; }
template<class T, class V, class W> void _print(tuple<T, V, W> t) { cout << "{"; _print(get<0>(t)); cout << " "; _print(get<1>(t)); cout << " "; _print(get<2>(t)); cout << "}"; }
template<class T> void _print(vector<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
// vector<bool> is bit-packed — dereferencing its iterator gives a temporary
// proxy, not a real bool&, which trav()'s `auto&` can't bind to. Iterate by
// value instead; this exact overload wins over the generic vector<T> one.
inline void _print(const vector<bool>& v) { cout << "[ "; for (bool b : v) cout << b << " "; cout << "]"; }
// Fixed-size C array, any dimension (int a[5], int a[3][4], ...). Binding by
// reference-to-array preserves the size and skips the pointer decay that
// would otherwise lose it; recurses cleanly since each row of a 2D array is
// itself a fixed-size array matching this same overload.
template<class T, size_t N> void _print(const T(&arr)[N]) { cout << "[ "; fo(idx, 0, (int)N) { _print(arr[idx]); cout << " "; } cout << "]"; }
template<class T> void _print(vector<vector<T>> v) { trav(i, v) { cout << "\n"; _print(i); } }
template<class T> void _print(set<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(multiset<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(unordered_set<T> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T, class V> void _print(map<T, V> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T, class V> void _print(unordered_map<T, V> v) { cout << "[ "; trav(i, v) { _print(i); cout << " "; } cout << "]"; }
template<class T> void _print(queue<T> q) { vector<T> t; cout << "[ "; while (!q.empty()) { _print(q.front()); cout << " "; t.pb(q.front()); q.pop(); } cout << "]"; trav(i, t) q.push(i); }
template<class T> void _print(pq<T> pqq) { vector<T> t; cout << "[ "; while (!pqq.empty()) { _print(pqq.top()); cout << " "; t.pb(pqq.top()); pqq.pop(); } cout << "]"; trav(i, t) pqq.push(i); }
template<class T> void _print(pqg<T> pqq) { vector<T> t; cout << "[ "; while (!pqq.empty()) { _print(pqq.top()); cout << " "; t.pb(pqq.top()); pqq.pop(); } cout << "]"; trav(i, t) pqq.push(i); }

// dbg(a, b, c, ...) — prints "a = <val>, b = <val>, c = <val>" on one line.
// Custom names: nm("label", expr) overrides the auto-derived label —
// dbg(nm("x half", x/2)) prints "x half = <val>".
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
template<typename T>
void _dbg_one(const string& fallback, const T& x) { cout << fallback << " = "; _print(x); }
template<typename T>
void _dbg_one(const string& fallback, const _DbgNamed<T>& x) { (void)fallback; cout << x.name << " = "; _print(x.value); }
inline void _dbg_print_all(vector<string>::iterator) { cout << "\n"; }
template<typename T, typename... Args>
void _dbg_print_all(vector<string>::iterator it, T&& first, Args&&... rest) {
  _dbg_one(*it, first);
  if (sizeof...(rest) > 0) cout << ", ";
  _dbg_print_all(++it, rest...);
}
#define dbg(...) do { auto _dbg_names = _dbg_split(#__VA_ARGS__); _dbg_print_all(_dbg_names.begin(), __VA_ARGS__); } while(0)
#else
#define dbg(...)
#endif

/********************************************************/
/* Generic list / tree helpers — templates, so they      */
/* compile fine even though ListNode/TreeNode aren't     */
/* declared yet (checked only once you call them, after  */
/* LeetCode's own struct definitions appear below).      */
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
  trav(x, v) { cur->next = new Node(x); cur = cur->next; }
  return dummy.next;
}
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
i64 inv(i64 a, i64 m = mod) { return power(a, m - 2, m); } // needs m prime, gcd(a,m)=1
i64 madd(i64 a, i64 b, i64 m = mod) { return (a + b) % m; }
i64 msub(i64 a, i64 b, i64 m = mod) { return ((a - b) % m + m) % m; }
i64 mmul(i64 a, i64 b, i64 m = mod) { return mulmod(a, b, m); }
i64 mdiv(i64 a, i64 b, i64 m = mod) { return mulmod(a % m, inv(b, m), m); } // needs m prime, gcd(b,m)=1

// NOTE: shadow std::gcd/std::lcm on purpose — non-template overloads win
// over the std:: templates during overload resolution, so this is safe.
i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }
i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
i64 ceil_div(i64 a, i64 b) { return (a + b - 1) / b; }

// Integer square root (largest x s.t. x*x <= n), correct across full i64 range.
i64 isqrt(i64 n) {
  if (n < 0) return -1;
  if (n == 0) return 0;
  i64 r = (i64)sqrtl((f80)n);
  while (r > 0 && r > n / r) r--;
  while ((r + 1) <= n / (r + 1)) r++;
  return r;
}
template<typename T> T sign(T x) { return (x > 0) - (x < 0); }

// container.size() as i32 instead of size_t — avoids signed/unsigned comparison
// warnings when mixing with int loop counters, e.g. fo(i, 0, sz(v))
template<class T> i32 sz(const T& c) { return (i32)c.size(); }

/********************************************************/

inline void _init() {
  static bool done = false;
  if (done) return;
  done = true;
  // precomp_factorials();
  // sieve();
  // sieve_primes();
  // sieve_spf();
}

// ---- Paste everything above this line into LeetCode, directly above your class Solution ----
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int sq = 1;
            dp[i] = 0;
            for (int j = i - sq * sq; j >= 0; j = i - ++sq * sq) {
                if (!dp[j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        // dbg(dp);

        return dp[n];
    }
};