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
template <typename T> inline bool smin(T& a, const T& b) {
  return b < a ? a = b, true : false;
}
template <typename T> inline bool smax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}

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
inline i64 rnd(i64 lo, i64 hi) {
  return uniform_int_distribution<i64>(lo, hi)(rng);
}

constexpr int FP_PREC = 15;
template <typename T> void print_fp(T x, int precision = FP_PREC) {
  cout << fixed << setprecision(precision) << x << '\n';
}

/********************************************************/
/* Macros & Loop Helpers                                */
/********************************************************/
#define fo(i, x, y, ...) for (i64 i = (x); i < (y); i += (1 __VA_OPT__(* 0 + (__VA_ARGS__))))
#define fr(i, x, y, ...) for (i64 i = (x); i >= (y); i -= (1 __VA_OPT__(* 0 + (__VA_ARGS__))))
#define fox(i, x, y, expr) for (i64 i = (x); i < (y); i = (expr))
#define frx(i, x, y, expr) for (i64 i = (x); i >= (y); i = (expr))
#define trav(a, b) for (auto& a : (b))
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

/********************************************************/
/* Debug System Setup (uses cout — visible in LeetCode's */
/* console, unlike cerr)                                 */
/********************************************************/
#define DEBUG_MODE 1

#if DEBUG_MODE
#define sl cout << string(20, '-') << "\n"
#define bl cout << string(40, '-') << "\n"
#else
#define sl
#define bl
#endif

template <typename T> void _print(T t) { cout << t; }
template <typename T, typename... Args> void _print(T t, Args... args) {
  cout << t << " ";
  _print(args...);
}
template <class T, class V> void _print(pair<T, V> p) {
  cout << "{";
  _print(p.ff);
  cout << " ";
  _print(p.ss);
  cout << "}";
}

template <class Tuple, size_t... Is>
void _print_tuple_impl(const Tuple& t, index_sequence<Is...>) {
  cout << "{";
  size_t idx = 0;
  ((cout << (idx++ ? " " : ""), _print(get<Is>(t))), ...);
  cout << "}";
}
template <class... Args> void _print(const tuple<Args...>& t) {
  _print_tuple_impl(t, index_sequence_for<Args...>{});
}

template <class T> void _print(vector<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
inline void _print(const vector<bool>& v) {
  cout << "[ ";
  for (bool b : v)
    cout << b << " ";
  cout << "]";
}
template <class T, size_t N> void _print(const T(&arr)[N]) {
  cout << "[ ";
  fo(idx, 0, (int)N) {
    _print(arr[idx]);
    cout << " ";
  }
  cout << "]";
}
template <class T, size_t N> void _print(const array<T, N>& arr) {
  cout << "[ ";
  trav(i, arr) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(vector<vector<T>>& v) {
  trav(i, v) {
    cout << "\n";
    _print(i);
  }
}
template<class T> void _print(stack<T>& s) {
  vector<T> t;
  while (!s.empty()) { t.pb(s.top()); s.pop(); }
  cout << "[ ";
  while (!t.empty()) {
    _print(t.back()); cout << " "; s.push(t.back()); t.pop_back();
  }
  cout << "]";
}
template <class T> void _print(queue<T>& q) {
  vector<T> t;
  cout << "[ ";
  while (!q.empty()) {
    _print(q.front());
    cout << " ";
    t.pb(q.front());
    q.pop();
  }
  cout << "]";
  trav(i, t) q.push(i);
}
template <class T> void _print(deque<T>& dq) {
  cout << "[ ";
  fo(i, 0, sz(dq)) {
    _print(dq.front());
    cout << " ";
    dq.pb(dq.front());
    dq.pop_front();
  }
  cout << "]";
}
template <class T> void _print(pq<T>& pqq) {
  vector<T> t;
  cout << "[ ";
  while (!pqq.empty()) {
    _print(pqq.top());
    cout << " ";
    t.pb(pqq.top());
    pqq.pop();
  }
  cout << "]";
  trav(i, t) pqq.push(i);
}
template <class T> void _print(pqg<T>& pqq) {
  vector<T> t;
  cout << "[ ";
  while (!pqq.empty()) {
    _print(pqq.top());
    cout << " ";
    t.pb(pqq.top());
    pqq.pop();
  }
  cout << "]";
  trav(i, t) pqq.push(i);
}
template <class T> void _print(set<T>& v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(multiset<T>& v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(unordered_set<T>& v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(map<T, V>& v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(unordered_map<T, V>& v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}

#if DEBUG_MODE
inline vector<string> _dbg_split(const string& s) {
  vector<string> res;
  string cur;
  int depth = 0;
  trav(c, s) {
    if (c == '(' || c == '[' || c == '{')
      depth++;
    if (c == ')' || c == ']' || c == '}')
      depth--;
    if (c == ',' && depth == 0) {
      res.pb(cur);
      cur.clear();
    } else
      cur += c;
  }
  res.pb(cur);
  trav(t, res) {
    size_t a = t.find_first_not_of(" \t");
    size_t b = t.find_last_not_of(" \t");
    t = (a == string::npos) ? "" : t.substr(a, b - a + 1);
  }
  return res;
}
template <typename T> struct _DbgNamed {
  const char* name;
  T value;
};
template <typename T> _DbgNamed<T> nm(const char* name, T value) {
  return _DbgNamed<T>{name, value};
}
template <typename T> void _dbg_one(const string& fallback, const T& x) {
  cout << fallback << " = ";
  _print(x);
}
template <typename T>
void _dbg_one(const string& fallback, const _DbgNamed<T>& x) {
  (void)fallback;
  cout << x.name << " = ";
  _print(x.value);
}
inline void _dbg_print_all(vector<string>::iterator) { cout << "\n"; }
template <typename T, typename... Args>
void _dbg_print_all(vector<string>::iterator it, T&& first, Args&&... rest) {
  _dbg_one(*it, first);
  if (sizeof...(rest) > 0)
    cout << ", ";
  _dbg_print_all(++it, rest...);
}
#define dbg(...)                                                               \
    do {                                                                       \
        auto _dbg_names = _dbg_split(#__VA_ARGS__);                            \
        _dbg_print_all(_dbg_names.begin(), __VA_ARGS__);                       \
    } while (0)
#else
#define dbg(...)
#endif

/********************************************************/
/* ListNode / TreeNode                                  */
/* LOCAL-only (compile with -DLOCAL): LeetCode's judge   */
/* already declares these, so leaving LOCAL undefined on */
/* submission skips this block and avoids redefinition.  */
/********************************************************/
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
/* Generic List / Tree Helpers (templated on Node, so    */
/* they bind to either the LOCAL structs above or         */
/* LeetCode's own ListNode/TreeNode)                      */
/********************************************************/
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

// Level-order build; `sentinel` (default INT_MIN) marks a missing child,
// e.g. {1,2,3,INT_MIN,4}.
template <class Node>
Node* buildTree(const vector<int>& v, int sentinel = INT_MIN) {
  if (v.empty() || v[0] == sentinel)
    return nullptr;
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
  if (!root)
    return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

/********************************************************/
/* Math Helpers                                         */
/********************************************************/
inline i64 mulmod(i64 a, i64 b, i64 m = mod) {
#if defined(__SIZEOF_INT128__)
  return (__int128)a * b % m;
#else
  i64 res = 0;
  a %= m;
  while (b > 0) {
    if (b & 1)
      res = (res + a) % m;
    a = (a + a) % m;
    b >>= 1;
  }
  return res;
#endif
}

i64 power(i64 base, i64 exp, i64 m = mod) {
  i64 res = 1;
  base %= m;
  while (exp > 0) {
    if (exp & 1)
      res = mulmod(res, base, m);
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
  if (n < 0)
    return -1;
  if (n == 0)
    return 0;
  i64 r = (i64)sqrtl((f80)n);
  while (r > 0 && r > n / r)
    r--;
  while ((r + 1) <= n / (r + 1))
    r++;
  return r;
}

template <typename T> T sign(T x) { return (x > 0) - (x < 0); }
template <class T> i32 sz(const T& c) { return static_cast<i32>(c.size()); }

/********************************************************/

static const int _fast_io = [] () {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // swap_mod();

  return 0;
}();

/********************************************************/

/*
 * PROBLEM
 * -------
 * Given nums, window size x (named `window`) and count k (named `subarrs`).
 * One operation changes any element by +1 or -1. Find the minimum number of
 * operations so that the array has at least k NON-overlapping subarrays of
 * length exactly x, each with all its elements equal.
 *
 * SOLUTION OVERVIEW (three stages, each feeding the next)
 * -------------------------------------------------------
 * Stage 0: Reduce the problem
 *   - The windows we pick are disjoint, so fixing one never affects another.
 *     The total cost is therefore the SUM of independent per-window costs.
 *   - Costs are >= 0, so a (k+1)-th window can never help. "At least k"
 *     is the same as "exactly k".
 *   - So the task becomes: choose k windows whose starts are at least x
 *     apart, minimizing the sum of cost[start]. First we need cost[start]
 *     for every start (Stage 1), then we choose the windows (Stage 2).
 *
 * Stage 1: cost[s] = min operations to make nums[s..s+x-1] all equal
 *   - Making the window equal to a value v costs sum |a_t - v|.
 *     This is minimized when v is the MEDIAN of the window
 *     (moving v toward the median shrinks more distances than it grows).
 *   - So cost[s] = sum |a_t - median|. Split at the median:
 *        low side  (elements <= m): cost m*lc - ls   (raise them to m)
 *        high side (elements >  m): cost rs - m*rc   (lower them to m)
 *     where lc/ls are the count/sum of the low side, and rc/rs of the high side.
 *   - Doing this naively is O(n*x). Instead we SLIDE the window one step at a
 *     time (one insert, one erase) and keep the window in two Fenwick trees
 *     indexed by VALUE:
 *        FT_cnt: how many window elements have each value
 *        FT_sum: sum of the window elements with each value
 *     Then, per window:
 *        - median  = the element of rank (x/2 + 1), found by a Fenwick
 *          "descent" (kth) in O(log V)
 *        - lc, ls  = one prefix query on each tree (everything <= median)
 *        - rc, rs  = derived from the window total and window size
 *   - Values may be negative, so every value is shifted by `offset` before
 *     being used as a Fenwick index (Fenwick trees need indices >= 1).
 *   - The trees are static (allocated once, not per call) and the last window
 *     is erased after Stage 1, so every call starts from an all-zero tree.
 *   - Cost of this stage: O(n log V), V = value range (2e6 here).
 *
 * Stage 2: DP to pick k non-overlapping windows
 *   - State: dp[j][i] = min cost using only the first i elements
 *     (a PREFIX LENGTH, so i = 0 is the empty prefix) and exactly j windows.
 *   - Look at the last element of the prefix. Either:
 *       (a) no chosen window ends there:  dp[j][i-1]
 *       (b) a window ends there. It covers elements i-x .. i-1 (0-indexed),
 *           so its cost is cost[i-x], and the other j-1 windows must fit in
 *           the first i-x elements:        dp[j-1][i-x] + cost[i-x]
 *     dp[j][i] = min(a, b). The jump back by x is what enforces non-overlap.
 *   - Base: dp[0][i] = 0 (no windows, no cost). Everything else starts at INF
 *     (impossible), so INF never wins a min. Guard the add against INF + cost.
 *   - Answer: dp[k][n].
 *   - Cost of this stage: O(n*k), about 1.5e6 steps for n = 1e5, k = 15.
 *
 * TOTAL: O(n log V + n*k) time.
 *
 * ASSUMPTIONS
 *   - |a[i]| <= 1e6. If the range is larger, grow offset/limit or
 *     coordinate-compress the values.
 *   - n >= window*subarrs (so a valid answer exists).
 */
class Solution {
  public:
  long long minOperations(vector<int>& a, int window, int subarrs) {
    int n = sz(a);

    // ---------- Stage 1 setup: value-indexed Fenwick trees ----------
    // A value v maps to Fenwick index v + offset, in [1, 2e6 + 1] < limit.
    int limit = 2e6 + 2, offset = 1e6 + 1;

    // topBit = largest power of two <= limit; the starting step for kth descent.
    int topBit = 1;
    while (2 * topBit <= limit) topBit <<= 1;

    // FT_cnt[idx]: number of window elements in the range this node covers
    // FT_sum[idx]: sum of window element values in that same range
    // FT_sum must be i64: a window sum can reach ~1e5 * 1e6 = 1e11.
    // CHANGED: static, so the 2e6-sized arrays are allocated once, not per call.
    static vi FT_cnt(limit, 0), FT_sum(limit, 0);

    // Rank of the median in the sorted window (1-indexed).
    // For odd windows this is the exact middle. For even windows it's the
    // upper median, which gives the same total cost as the lower median.
    auto get_median = [&] () -> int { return window / 2 + 1; };

    // Insert (d = +1) or erase (d = -1) value v. Walk UP the tree by lowbit,
    // updating every node whose range contains the index.
    auto update = [&] (int v, int d) {
      fo(idx, v + offset, limit, idx & (-idx)) {
        FT_cnt[idx] += d;
        FT_sum[idx] += v * d;
      }
    };

    // Fenwick descent: returns the smallest index whose prefix count >= k,
    // i.e. the shifted index of the k-th smallest element in the window.
    // Single O(log V) pass: jump over a block whenever it holds fewer than k
    // elements, subtracting what we skipped from k. Valid because counts are
    // non-negative, so prefix counts only grow.
    auto kth = [&] (int k) -> int {
      int pos = 0;
      for (int b = topBit; b > 0; b >>= 1) {
        int np = pos + b;
        if (np < limit && FT_cnt[np] < k) {
          pos = np;
          k -= FT_cnt[np];
        }
      }
      return pos + 1;
    };

    // Cost of the CURRENT window. `sum` is the running window total.
    auto _cost = [&] (i64& sum) -> i64 {
      // Prefix query over real values <= pos. Walk DOWN by lowbit.
      auto presum = [&] (int pos, vi& FT) -> i64 {
        i64 r = 0;
        fr(i, pos + offset, 1, i & (-i)) r += FT[i];
        return r;
      };

      int median = kth(get_median()) - offset;   // shifted index -> real value

      i64 ls = presum(median, FT_sum),           // sum of elements <= median
        rs = sum - ls,                           // sum of elements >  median
        lc = presum(median, FT_cnt),             // count of elements <= median
        rc = window - lc;                        // count of elements >  median

      // Raise the low side up to the median, lower the high side down to it.
      return (median * lc - ls) + (rs - median * rc);
    };

    // ---------- Stage 1: cost of every window by sliding ----------
    // cost[s] = cost of the window starting at index s, s in [0, n - window].
    vector<i64> cost;
    i64 sum = accumulate(a.begin(), a.begin() + window, 0ll);

    // First window: insert its elements, then read its cost.
    fo(i, 0, window) update(a[i], 1);
    cost.pb(_cost(sum));

    // Each slide: drop the element leaving on the left, add the one entering
    // on the right, keep the running sum in step, then read the cost.
    fo(i, window, n) {
      update(a[i - window], -1);
      update(a[i], 1);
      sum += a[i] - a[i - window];
      cost.pb(_cost(sum));
    }

    // CHANGED: erase the last window so the static trees are all zero again
    // for the next call.
    fo(i, n - window, n) update(a[i], -1);

    // ---------- Stage 2: DP over (windows chosen, prefix length) ----------
    // dp[j][i]: min cost using the first i elements and exactly j windows.
    // Size (k+1) x (n+1): row 0 = "no window chosen", column 0 = "empty prefix".
    vvi dp(subarrs + 1, vi(n + 1, INF));
    fo(i, 0, n + 1) dp[0][i] = 0;   // zero windows cost nothing, for any prefix

    fo(j, 1, subarrs + 1) {
      fo(i, 1, n + 1) {
        // Case (a): element i is not the end of a window; inherit from the
        // shorter prefix with the same number of windows.
        dp[j][i] = dp[j][i - 1];

        // Case (b): a window ends at element i. It spans elements
        // i-window .. i-1, so it starts at index i-window and costs
        // cost[i-window]. The other j-1 windows must fit in the first
        // i-window elements. Needs i >= window and a reachable earlier state.
        if (i - window >= 0 && dp[j - 1][i - window] < INF) {
          smin(dp[j][i], dp[j - 1][i - window] + cost[i - window]);
        }
      }
    }

    // All n elements available, exactly `subarrs` windows chosen.
    return dp[subarrs][n];
  }
};
