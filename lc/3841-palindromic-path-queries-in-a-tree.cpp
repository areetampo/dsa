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
 ======================================================================
  PALINDROME PATH QUERIES ON A TREE WITH UPDATES
 ======================================================================

  GOAL
  ----
  For a query (u, v): can the characters on the path u..v be rearranged
  into a palindrome? Node characters can change between queries.

  STEP 1: Palindrome check via a bitmask
  --------------------------------------
  A multiset of chars can form a palindrome iff at most ONE letter has an
  odd count. Represent a char c as the bit (1 << (c - 'a')). XORing masks
  toggles parity, so the XOR of all chars on a path is a 26-bit mask whose
  set bits are exactly the letters with odd count.
  Palindrome possible  <=>  popcount(mask) <= 1.

  STEP 2: Static version (no updates)
  -----------------------------------
  Root the tree at 0. Let P[u] = XOR of masks on the path root -> u.
  For a query (u, v) with l = lca(u, v):
        P[u] ^ P[v]        -> everything above l cancels, and l itself
                              cancels too (it appears in both P[u], P[v])
        ^ mask(s[l])       -> put l back, since it IS on the path
  So  mask(path) = P[u] ^ P[v] ^ mask(s[l]).

  STEP 3: LCA with binary lifting
  -------------------------------
  up[j][v] = the 2^j-th ancestor of v. The tree never changes, so this is
  built once. lca() first lifts the deeper node to the same depth, then
  lifts both together while their ancestors differ. O(log n) per query.
  The root's parent is itself (up[0][0] = 0), which keeps lifting safe.

  STEP 4: Why updates are hard
  ----------------------------
  Changing the char at node x changes P[w] for EVERY w in x's subtree
  (those are exactly the nodes whose root-path contains x), and each by
  the same value:   delta = mask(old) ^ mask(new).
  Looping over the subtree per update is too slow, so we need a fast way
  to apply "XOR delta onto a whole subtree".

  STEP 5: Subtree -> contiguous range (Euler tour)
  ------------------------------------------------
  tin[x]  = DFS entry order of x.
  tout[x] = largest tin inside x's subtree.
  Every subtree is the contiguous block [tin[x], tout[x]] of positions.
  (Siblings must start AFTER the previous sibling's whole subtree, which
  is why each child's tin is max_subtree_time + 1.)

  STEP 6: "Stamps" in a Fenwick tree (BIT)
  ----------------------------------------
  On update of x, place two stamps of value delta on a position line:
        at tin[x]       ("from here on, delta applies")
        at tout[x] + 1  ("from here on, cancel it")
  The correction for node u is the XOR of all stamps at positions
  <= tin[u]. For one updated node x:
     - u inside x's block  (x is an ancestor of u or x == u):
         only the start stamp is read      -> delta included
     - u after x's block: both stamps read -> cancel
     - u before x's block: none read       -> nothing
  So correction(u) = XOR of deltas of exactly the updated nodes on the
  root -> u path. The BIT only does "prefix XOR of stamps" in O(log n).
  P[] stays based on the ORIGINAL string and is never modified.

  STEP 7: Final query formula
  ---------------------------
     mask = (P[u] ^ corr(u)) ^ (P[v] ^ corr(v)) ^ mask(CURRENT s[l])
  s[] is kept current on updates, because l's char is read from it.
  Answer = popcount(mask) <= 1.

  COMPLEXITY
  ----------
  Preprocessing O(n log n). Each update/query O(log n).

  NOTE
  ----
  The recursive DFS goes n deep on a path-shaped tree (n up to 5e4).
  It passes on LeetCode, but convert to an iterative DFS if you hit
  stack overflows elsewhere.
 ======================================================================
*/
class Solution {
  public:

  int n, LOG;                     // n = nodes, LOG = number of lifting levels
  string s;                       // CURRENT chars (updated on every update)
  vector<vector<int>> tree, up;   // adjacency list, binary lifting table
  vector<int> depth;              // depth[v] = distance from root
  vector<int> tin, tout;          // Euler-tour range of v's subtree
  vector<int> P;                  // root->v XOR mask using the ORIGINAL string
  vector<int> FT;                 // Fenwick tree holding the stamps (1-indexed)

  // One DFS fills everything static:
  //   v: current node, p: parent, t: tin to assign to v,
  //   XOR: mask of the root->v path (original chars).
  // Returns tout[v], the last tin used in v's subtree.
  int dfs(int v, int p, int t, int XOR) {
    tin[v] = t;                   // entry time = start of v's block
    up[0][v] = p;                 // 1st ancestor is the parent
    P[v] = XOR;                   // root->v path mask
    // Fill higher levels: the 2^i-th ancestor is the 2^(i-1)-th ancestor of
    // the 2^(i-1)-th ancestor. Ancestors are already filled (top-down DFS).
    fo(i, 1, LOG) up[i][v] = up[i - 1][up[i - 1][v]];

    int max_subtree_time = t;     // largest tin used so far inside v's subtree
    trav(c, tree[v]) {
      if (c == p) continue;       // don't walk back to the parent
      depth[c] = depth[v] + 1;
      // Child starts right after everything visited so far, so sibling
      // blocks never overlap. Child's path mask = parent's ^ child's char.
      max_subtree_time = dfs(c, v, max_subtree_time + 1,
                             XOR ^ (1 << (s[c] - 'a')));
    }
    return tout[v] = max_subtree_time;   // v's block is [tin[v], tout[v]]
  }

  // Lift v up by k levels by reading the bits of k (jump 2^i for each set bit).
  int ancestor(int v, int k) {
    fo(i, 0, LOG) if (k & (1ll << i)) v = up[i][v];
    return v;
  }

  // Lowest common ancestor via binary lifting.
  int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);        // make u the deeper one
    u = ancestor(u, depth[u] - depth[v]);       // equalize depths
    if (u == v) return u;                       // one was ancestor of the other
    // Lift both as far as possible while they stay different; the LCA is
    // then the common parent.
    fr(i, LOG - 1, 0) if (up[i][u] != up[i][v]) u = up[i][u], v = up[i][v];
    return up[0][u];
  }

  // Change node idx to new_char: place the two stamps.
  void update(int idx, char new_char) {
    char old_char = s[idx]; s[idx] = new_char;  // keep s current (LCA needs it)
    // XOR of old and new masks = removes old char, adds new char.
    int val = (1 << (old_char - 'a')) ^ (1 << (new_char - 'a'));
    // Start stamp at position tin[idx] (+1 since the Fenwick tree is 1-indexed).
    for (int start = tin[idx] + 1; start <= n; start += start & -start)
      FT[start] ^= val;
    // End stamp at position tout[idx]+1 (+1 again for 1-indexing). If it is
    // past n, no node reads it, so skipping is safe (loop doesn't run).
    for (int end = tout[idx] + 2; end <= n; end += end & -end)
      FT[end] ^= val;
  }

  // Fenwick prefix XOR: XOR of stamps at 1-indexed positions 1..idx.
  int query(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) res ^= FT[idx];
    return res;
  }

  // Correction for the root->u path: XOR of stamps at positions <= tin[u].
  // Only updated ancestors of u (or u itself) survive; the rest cancel.
  int correction(int u) {
    return query(tin[u] + 1);
  }

  vector<bool> palindromePath(int N, vector<vector<int>>& edges, string S,
                              vector<string>& queries) {
    n = N, s = S, LOG = 1;
    while ((1LL << LOG) <= n) LOG++;            // enough levels to cover depth < n

    // Allocate everything.
    tree.assign(n, {});
    up.assign(LOG, vector<int>(n));
    depth.assign(n, 0);
    tin.resize(n), tout.resize(n);
    P.assign(n, 0); FT.assign(n + 2, 0);        // BIT starts empty (no stamps)

    // Build the undirected adjacency list.
    trav(i, edges) {
      tree[i[0]].pb(i[1]);
      tree[i[1]].pb(i[0]);
    }

    // Root at 0 (its own parent). Its path mask is just its own char.
    dfs(0, 0, 0, 1 << (s[0] - 'a'));

    vb res;

    // Process queries in order (updates affect later queries only).
    trav(q, queries) {
      stringstream qq(q);
      string type; int idx, u, v; char c;
      if (q[0] == 'u') {                        // "update idx c"
        qq >> type >> idx >> c;
        update(idx, c);
      } else {                                  // "query u v"
        qq >> type >> u >> v;
        // root->u and root->v masks = static P ^ correction, XORed
        // together; then add back the LCA's CURRENT char.
        int r = P[u] ^ P[v] ^ correction(u) ^ correction(v) ^
                (1 << (s[lca(u, v)] - 'a'));
        res.pb(popcount(r) <= 1);               // at most one odd-count letter
      }
    }

    return res;
  }
};