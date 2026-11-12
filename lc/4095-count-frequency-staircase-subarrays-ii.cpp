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
// i64 greater = sz(s) - s.order_of_key({ val, INF });
// i64 equal = s.order_of_key({ val, INF }) - s.order_of_key({ val, -INF });
// i64 less = s.order_of_key({ val, -INF });
// erase not remove

/********************************************************/
/* Utility Functions & Constants                        */
/********************************************************/
template <typename T> inline bool smin(T& a, const T& b) {
  return b < a ? a = b, true : false;
}
template <typename T> inline bool smax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}

constexpr int dir[5] = { 1, 0, -1, 0, 1 }; // dx = dir[i], dy = dir[i+1]
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
#define fo(i, x, y) for (i64 i = (x); i < (y); ++i)
#define foi(i, x, y, inc) for (i64 i = (x); i < (y); i += (inc))
#define fr(i, x, y) for (i64 i = (x); i >= (y); --i)
#define frd(i, x, y, dec) for (i64 i = (x); i >= (y); i -= (dec))
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
template <class T> void _print(vector<vector<T>> v) {
  trav(i, v) {
    cout << "\n";
    _print(i);
  }
}
template <class T> void _print(set<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(multiset<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T> void _print(unordered_set<T> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V> void _print(unordered_map<T, V> v) {
  cout << "[ ";
  trav(i, v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template<class T> void _print(stack<T> s) {
  vector<T> t;
  while (!s.empty()) { t.pb(s.top()); s.pop(); }
  cout << "[ ";
  while (!t.empty()) {
    _print(t.back()); cout << " "; s.push(t.back()); t.pop_back();
  }
  cout << "]";
}
template <class T> void _print(queue<T> q) {
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
template <class T> void _print(pq<T> pqq) {
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
template <class T> void _print(pqg<T> pqq) {
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
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x), left(left), right(right) {
  }
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


/* ==================== BRUTE FORCE LOGIC ====================

part 1: n <= 1500

Fix a start index i and extend the end j to the right, one element at
a time.

- Each value gets a RANK when it first appears in the window(1st new
value->rank 1, 2nd new value->rank 2, ...).
- A value of rank r must appear exactly r times, so after its first
occurrence it still NEEDS(r - 1) more copies.
- Keep a map : value->copies still needed.
* new value : needed = distinct_so_far - 1
* existing, needed > 0 : needed--
* existing, needed == 0 : it already has its full count and appeared
again.Its frequency exceeds its rank and
this can never be undone, so no longer
window from this i can be valid->stop
and move to the next i.
- Instead of erasing from the map when needed hits 0, keep it as 0 and
maintain a counter x = number of values whose needed == 0.
(A value never leaves 0 without triggering the stop above, so x
  never decreases.)
- The window[i..j] is a staircase iff x == distinct, i.e.every
value's need is 0. Then res++.

Cost: for each i we may walk to the end of the array->O(n ^ 2)
(O(n ^ 2 log n) with an ordered map).Too slow for n = 5e4, e.g.an
all - distinct array never triggers the stop, so every i walks to the end.

==================== OPTIMIZATION ====================

part 2: n <= 5e4

Key fact : a staircase with k distinct values has length
1 + 2 + ... + k = k(k + 1) / 2, and the whole array has only n elements,
so k(k + 1) / 2 <= n->k <= ~315 for n = 5e4.

EXTRA STOP RULE : while extending j from start i, `distinct` never
decreases.If distinct* (distinct + 1) / 2 > (n - i), a staircase with that
many distinct values cannot fit in the remaining suffix, and it only
gets worse as j grows->stop this i.

Why the total work becomes small(counting per POSITION p) :
-Suppose starts i1 < i2 < ... < ik all walk through position p
without stopping.
- The start value of each walk has rank 1, so it cannot appear again
inside its own surviving window.Since i1's window covers i2..ik,
the values a[i1], a[i2], ..., a[ik] are all pairwise different.
- They all lie inside one surviving window, which has at most ~315
distinct values(by the extra stop rule).So k <= ~315.
- So every position is stepped over by at most ~315 starts:
total steps <= n * 315 ~1.6e7->O(n * sqrt(n)).

The per - step work is still O(1); we just prove most walks die early.
The answer is at most that many steps, so it fits in an int.
======================================================================
*/

class Solution {
  public:
  int countStaircase(vector<int>& a) {
    int n = sz(a);

    // need[i] = copies of i still required in the current window
    // -1 means v has not appeared in the current window
    vector<int> need(100001, -1);

    // values touched in the current walk, so we can reset only those
    // (a full reset of need[] for every i would cost O(maxValue) each)
    vector<int> touched;

    int res = 0;

    fo(i, 0, n) {
      int distinct = 0; // cnt of distinct values in window
      int no_need = 0; // cnt of values with need == 0
      i64 rem = n - i; // elements available from i onward

      fo(j, i, n) {
        int v = a[j];

        if (need[v] == -1) {
          // new value: it gets rank = distinct + 1
          distinct++;

          // optimization: a staircase with `distinct` values needs
          // distinct*(distinct+1)/2 elements; if the suffix is
          // shorter, no end j can ever work for this i
          if ((i64)distinct * (distinct + 1) / 2 > rem) break;

          need[v] = distinct - 1; // rank - 1 more copies needed
          touched.pb(v); // to reset it in need[] later
          if (need[v] == 0) no_need++; // first el of subarr: rank 1 done
        } else if (need[v] == 0) {
          // value already has its full count but appeared again:
          // frequency > rank, subarr permanently invalid, next i
          break;
        } else {
          // copy of an existing value found
          if (--need[v] == 0) no_need++; // this value done
        }

        // every distinct value has exactly its rank copies
        // window [i..j] is a frequency staircase
        if (no_need == distinct) res++;
      }

      // reset only what this subarr/walk touched
      trav(v, touched) need[v] = -1;
      touched.clear();
    }

    return res;
  }
};
