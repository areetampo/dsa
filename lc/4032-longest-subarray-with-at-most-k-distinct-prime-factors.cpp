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
#define alln(x, n) (x), (x) + (n)

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

// Prime sieves — pick whichever variant fits: sieve() for primality checks
// only; sieve_primes() when you also need the list of primes; sieve_spf()
// for fast repeated factorization via factorize()/factorize_exp().
//
// Complexity: all three sieves are O(n log log n); factorize/factorize_exp
// are O(log x) each after sieve_spf().
//
// Usage:
//   sieve(1000000);              // then: is_prime[17] -> true
//   sieve_primes(1000000);       // then: primes -> [2, 3, 5, 7, ...]
//   sieve_spf(1000000);          // then: factorize(60) -> [2, 2, 3, 5]
//                                //       factorize_exp(60) -> [{2,2},{3,1},{5,1}]
//
// NOTE: MAXN is guarded with #ifndef so this can be safely pasted alongside
// combinatorics.cpp (which also defines MAXN) without a duplicate-definition
// error — whichever file gets pasted first "wins" and sets the shared value.
#ifndef MAXN
#define MAXN 2000005
#endif

// 1. Basic sieve — is_prime[i] = true if i is prime
//    Use when: just need primality checks up to n
vector<bool> is_prime;
void sieve(i64 n = MAXN) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (i64 i = 2; i * i <= n; i++)
    if (is_prime[i])
      foi(j, i * i, n + 1, i)
      is_prime[j] = false;
}

// 2. Sieve with primes list — also collects all primes
//    Use when: you need to iterate over primes or count them
vi primes;
void sieve_primes(i64 n = MAXN) {
  is_prime.assign(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  fo(i, 2, n + 1) {
    if (is_prime[i]) {
      primes.pb(i);
      foi(j, i * i, n + 1, i)
        is_prime[j] = false;
    }
  }
}

// 3. Linear sieve — O(n), also gives smallest prime factor (spf)
//    Use when: need fast factorization of many numbers
//    Factorize x: while (x > 1) { factor = spf[x]; x /= spf[x]; }
vi spf; // spf[i] = smallest prime factor of i
void sieve_spf(i64 n = MAXN) {
  spf.resize(n + 1);
  iota(all(spf), 0); // spf[i] = i initially
  for (i64 i = 2; i * i <= n; i++)
    if (spf[i] == i) // i is prime
      foi(j, i * i, n + 1, i)
      if (spf[j] == j) spf[j] = i;
}
// Get all prime factors of x using spf (after sieve_spf)
vi factorize(i64 x) {
  vi factors;
  while (x > 1) { factors.pb(spf[x]); x /= spf[x]; }
  return factors;
}
// Get distinct prime factors with exponents
vector<pi> factorize_exp(i64 x) {
  vector<pi> factors;
  while (x > 1) {
    i64 p = spf[x], cnt = 0;
    while (x % p == 0) { x /= p; cnt++; }
    factors.pb({ p, cnt });
  }
  return factors;
}

vvi factors;
inline void _init() {
  static bool done = false;
  if (done) return;
  done = true;
  // precomp_factorials();
//   sieve();
//   sieve_primes();
  sieve_spf();
  factors.resize(1e5 + 1);
        for (int i = 2; i <= 1e5; i++)
            factors[i] = factorize(i);
}
// ---- Paste everything above this line into LeetCode, directly above your class Solution ----
class Solution {
public:
    int longestSubarray(vector<int>& v, int k) {
        // vals needed for factorisation: sqrt(max(v)) = sqrt(1e5)
        _init();
        
        unordered_map<int, int> m; // distinct primes in a window
        int r = 0;

        // tc: n * sqrt(max(v))
        for (int i = 0, j = 0; j < v.size(); j++) {
            for (int factor : factors[v[j]]) 
                m[factor]++;

            while (m.size() > k) {
                for (int factor : factors[v[i]]) 
                    if (--m[factor] == 0)
                        m.erase(factor);
                i++;
            } 

            r = max(r, j - i + 1);
        }

        return r;
    }
};