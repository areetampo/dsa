#include <bits/stdc++.h>
using namespace std;
#define i32 int32_t
#define i64 int64_t
#define u32 uint32_t
#define u64 uint64_t
#define f32 float
#define f64 double
#define f80 long double
typedef vector<i64> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<i64, i64> pi;
typedef tuple<i64, i64, i64> ti;
typedef pair<char, char> pc;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T, typename S> void smin(S& a, const T& b) { if (a > b) a = b; }
template <typename T, typename S> void smax(S& a, const T& b) { if (a < b) a = b; }
const i32 MOD = 1000000007, MOD1 = 998244353;
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FOR1(i, x, y, inc) for (int i = x; i < y; i += inc)
#define FOR2(i, x, y, exp) for (int i = x; i < y; i++) {exp}
#define FORR(i, x, y) for (int i = x; i >= y; i--)
#define FORR1(i, x, y, dec) for (int i = x; i >= y; i -= dec)
#define FORR2(i, x, y, exp) for (int i = x; i >= y; i--) {exp}
#define trav(a, b) for (auto& a : b)
#define ff first
#define ss second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes\n";
#define no cout << "No\n";
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << #__VA_ARGS__ << " ", _print(__VA_ARGS__), cerr << "\n";
#else
#define dbg(...)
#endif
template<typename T>
void _print(T t) { cerr << t; }
template<typename T, typename... Args>
void _print(T t, Args... args) { cerr << t << ", "; _print(args...); }
template<class T, class V> void _print(pair <T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template<class T> void _print(vector <T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(vector<vector<T>> v) { trav(i, v) { cerr << endl; _print(i); } }
template<class T> void _print(queue<T> q) { vector<T> t; cerr << "[ "; while (!q.empty()) { _print(q.front()); cerr << " "; t.pb(q.front()); q.pop(); } cerr << "]"; trav(i, t) q.push(i); }
template<class T> void _print(pq<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(pqg<T> pq) { vector<T> t; cerr << "[ "; while (!pq.empty()) { _print(pq.top()); cerr << " "; t.pb(pq.top()); pq.pop(); } cerr << "]"; trav(i, t) pq.push(i); }
template<class T> void _print(unordered_set <T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(set <T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T> void _print(multiset <T> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(unordered_map <T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
template<class T, class V> void _print(map <T, V> v) { cerr << "[ "; trav(i, v) { _print(i); cerr << " "; } cerr << "]"; }
inline void small_line() { cerr << "--------------------\n"; }
inline void big_line() { cerr << "------------------------------------------\n"; }
template <class T = i64> vector<T> inp(i64 n) { vector<T> v(n); FOR(i, 0, n) cin >> v[i]; return v; }
template <class T = i64> vector<vector<T>> inpM(i64 n, i64 m) { vector<vector<T>> v; FOR(i, 0, n) v.pb(inp(m)); return v; }
template <class T = i64, class S = i64> vector<pair<T, S>> inpPairs(i64 n) { vector<pair<T, S>> v(n); FOR(i, 0, n) { cin >> v[i].ff >> v[i].ss; } return v; }
i64 power(i64 base, i64 exponent) { i64 result = 1; while (exponent > 0) { if (exponent % 2 == 1) { result = (result * base) % MOD; } base = (base * base) % MOD; exponent /= 2; } return result; }
i64 sqrt(i64 x) { i32 i = 0, j = INT_MAX; while (i < j) { i64 mid = (j - i) / 2 + i; if (mid * mid <= x) { i = mid + 1; } else { j = mid; } } return i - 1; }
/********************************************************/

inline void solve() {
  // int z, o, k; cin >> z >> o >> k;
  // if (abs(z - o) > k) {
  //   cout << "-1\n";
  //   return;
  // }
  // vc v = { '0', '1' };
  // int mx = max(z, o), mn = min(z, o);
  // if (o > z) swap(v[0], v[1]);
  // int q = mx / (mn + 1), r = mx % (mn + 1);
  // //r is the leftover mx 
  // //q is the number of mx to be placed then 1 mn placed
  // //eg: 20 0s 7 1s
  // // 00 1 00 1 00 1 00 1 00 1 00 1 00 1 00, 4 0s left
  // //insert r = leftover 0s as spaced as possible in mn + q * (mn + 1) places
  // //len = 23 r = 4 -> 23 / (4 + 1) = 4, place r 0s after 4 steps each
  // int x = (mn + q * (mn + 1)) / (r + 1), placed_r = 0;
  // // dbg(q, r, x);
  // string res;
  // // while (res.size() < o + z) {
  // //   res += string(q, v[0]);
  // //   res += string(mn > 0, v[1]);
  // //   mn--;
  // //   if (res.size() >= placed_r * x + x && r > 0) {
  // //     res = res.substr(0, placed_r * x + x) + string(1, v[0]) +
  // //       res.substr(placed_r * x + x);
  // //     r--;
  // //     placed_r++;
  // //   }
  // // }
  // for (int i = 0; i < k; i++) res += v[0];
  // for (int i = 0; i < min(mx - k, mn); i++) res += v[1], res += v[0];
  // for (int i = 0; i < mn - min(mx - k, mn); i++) res += v[1];
  // int mx_bf = 0;
  // // for (int i = 0; i < res.size(); i++) {
  // //   for (int j = i, zz = 0; j < res.size(); j++) {
  // //     if (res[j] == '0') zz++;
  // //     mx_bf = max({ mx_bf, j - i + 1 - zz - zz, zz - ((j - i + 1) - zz) });
  // //   }
  // // }
  // // dbg(mx_bf); dbg(res);
  // cout << res << "\n";
  int n, s; cin >> n >> s;
  vi v = inp(n);
  int r = -1;
  for (int i = 0, j = 0, rs = 0; j < n; j++) {
    rs += v[j];
    while (rs > s) rs -= v[i++];
    if (rs == s) r = max(r, j - i + 1);
  }
  cout << (r == -1 ? -1: n - r) << "\n";
}

/********************************************************/
i32 main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("err.txt", "w", stderr);
#endif
  clock_t clock_start = clock();
  big_line();
  i32 t = 1;
  cin >> t;
  while (t--) {
    solve();
    big_line();
  }
  clock_t clock_end = clock();
  cerr << "Time: " << (double)(clock_end - clock_start) / CLOCKS_PER_SEC << "s";
  return 0;
}