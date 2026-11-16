#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<vl> vvl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pl> vpl;
typedef vector<vpl> vvpl;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define f1(i, a) for (int i=0; i<(a); i++)
#define f2(i, a, b) for (int i=a; i<(b); i++)
#define f1r(i,a) for (int i = (a)-1; i >= 0; i--)
#define f2r(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define trav1(i, m) for (auto i = m.begin(); i != m.end(); ++i)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Yes cout << "YES" << endl;
#define No cout << "NO" << endl;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
vi inp(int n) {
    vi v(n);
    f1(i, n) cin >> v[i];
    return v;
}
vl inpLL(int n) {
    vl v(n);
    f1(i, n) cin >> v[i];
    return v;
}
vpi inpCoordinates(int n) {
    vpi v(n);
    f1(i, n) {
        cin >> v[i].ff >> v[i].ss;
    }
    return v;
}
vpl inpCoordinatesLL(int n) {
    vpl v(n);
    f1(i, n) {
        cin >> v[i].ff >> v[i].ss;
    }
    return v;
}
vvi inpAdjListUnweighted(bool undirected) {
    int n; cin >> n;
    vvi v(n);
    while (n--) {
        int x, y; cin >> x >> y;
        v[x].pb(y);
        if (undirected) v[y].pb(x);
    }
    return v;
}
vvi inpAdjMatrixUnweighted(bool undirected) {
    int n; cin >> n;
    vvi v(n, vi(n, 0));
    while (n--) {
        int x, y; cin >> x >> y;
        v[x][y] = 1;
        if (undirected) v[y][x] = 1;
    }
    return v;
}
vvpi inpAdjListWeighted(bool undirected) {
    int n; cin >> n;
    vvpi v(n);
    while (n--) {
        int x, y, w; cin >> x >> y >> w;
        v[x].pb({ y, w });
        if (undirected) v[y].pb({ x, w });
    }
    return v;
}
vvi inpAdjMatrixWeighted(bool undirected, int placeholderForNoEdgeWt) {
    int n; cin >> n;
    vvi v(n, vi(n, placeholderForNoEdgeWt));
    while (n--) {
        int x, y, w; cin >> x >> y >> w;
        v[x][y] = w;
        if (undirected) v[y][x] = w;
    }
    return v;
}
template<class T>
void pr(const T& v) {
    trav(a, v) cout << a << " ";
    cout << endl;
}
template<class T>
void pr2(const T& v) {
    trav(a, v) pr(a);
}
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
ll gcdExtended(ll a, ll b, ll* x, ll* y) {
    if (a == 0) {
        *x = 0, * y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
ll modInverse(ll b, ll m) {
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}
int modDiv(ll a, ll b, int m = MOD) {
    return (int)(modInverse(b, m) * (a % m) % m);
}
ll poww(ll base, int exponent) {
    if (!exponent) return 1;
    if (exponent == 1) return base;
    ll temp = poww(base, exponent / 2);
    return (exponent % 2 ? base : 1) * temp * temp;
}
int sqrt(ll x) {
    ll i = 0, j = INT_MAX;
    while (i < j) {
        ll mid = (i + j) >> 1;
        if (mid * mid <= x) {
            i = mid + 1;
        } else {
            j = mid;
        }
    }
    return i - 1;
}
int msbPos(int n) {
    return 31 - __builtin_clz(n);
}
int lsbPos(int n) {
    return n == INT_MIN ? 31 : msbPos((n & (n - 1)) ^ n);
}
int bits(int n) {
    return __builtin_popcount(n);
}
pair<int, pair<int, int>> manhattanDistance(vector<vector<int>>& p, int delIdx) {//returns distance, points that enclose the distance
    int n = p.size();
    int mxSum = INT_MIN, mnSum = INT_MAX, mxDiff = INT_MIN, mnDiff = INT_MAX;
    int mxSumIdx = -1, mnSumIdx = -1, mxDiffIdx = -1, mnDiffIdx = -1;
    for (int i = 0; i < n; ++i) {
        if (i == delIdx) continue;
        int sum = p[i][0] + p[i][1];
        int diff = p[i][0] - p[i][1];
        if (sum > mxSum) {
            mxSum = sum;
            mxSumIdx = i;
        }
        if (sum < mnSum) {
            mnSum = sum;
            mnSumIdx = i;
        }
        if (diff > mxDiff) {
            mxDiff = diff;
            mxDiffIdx = i;
        }
        if (diff < mnDiff) {
            mnDiff = diff;
            mnDiffIdx = i;
        }
    }
    // cout << "mxSum: " << mxSum << " mnSum: " << mnSum << " mxDiff: " << mxDiff << " mnDiff: " << mnDiff << endl;
    // cout << "mxSumIdx: " << mxSumIdx << " mnSumIdx: " << mnSumIdx << " mxDiffIdx: " << mxDiffIdx << " mnDiffIdx: " << mnDiffIdx << endl;
    if (mxSum - mnSum > mxDiff - mnDiff) {
        return { mxSum - mnSum, {mxSumIdx, mnSumIdx} };
    } else {
        return { mxDiff - mnDiff, {mxDiffIdx, mnDiffIdx} };
    }
}
class Bit {
public:
    ll x;
    int sz;
    vl v;
    Bit(ll x, int sz) {
        this->x = x;
        this->sz = sz;
        v = vl(sz, 0);//0 -> sz - 1 === msb -> lsb
        rep();
    }
    void rep() {
        int i = sz - 1;
        while (x) {
            v[i--] = x & 1;
            x >>= 1;
        }
    }
    ll val() {
        ll res = 0;
        f1(i, sz) {
            res <<= 1;
            res |= v[i];
        }
        return res;
    }
};
class ST {
public:
    int n;
    vi v;
    vi tree;
    ST(vi v) {
        this->n = v.size();
        this->v = v;
        tree = vi(4 * n, 0);
        buildTree(0, 0, n - 1);
    }
    int buildTree(int idx, int s, int e) {
        if (s == e) return tree[idx] = v[s];
        return tree[idx] = buildTree(2 * idx + 1, s, s + (e - s) / 2) + buildTree(2 * idx + 2, s + (e - s) / 2 + 1, e);
    }
    // int q(int i, int j, int idx = 0, int s = 0, int e = this->n - 1) {
    //     if (j < s || e < i) return;
    //     if (i <= s && e <= j) return tree[idx];
    //     return q(idx * 2 + 1, s, s + (e - s) / 2, i, j) +
    //     q(idx * 2 + 2, s + (e - s) / 2 + 1, e, i, j);
    // }
};
class DSU {
    int n;
    vi par;
    vi rank;
    vi size;
public:
    DSU(int n) {
        this->n = n;
        par.resize(n + 1);
        for (int i = 0; i <= n; i++) par[i] = i;
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
    }
    int findPar(int x) {
        if (par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }
    void unionByRank(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);
        if (parX == parY) return;
        if (rank[parX] == rank[parY]) {
            par[parY] = parX;
            rank[parX]++;
        } else if (rank[parX] > rank[parY]) par[parY] = parX;
        else par[parX] = parY;
    }
    void unionBySize(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);
        if (parX == parY) return;
        if (size[parX] >= size[parY]) {
            par[parY] = parX;
            size[parX] += size[parY];
        } else {
            par[parX] = parY;
            size[parY] += size[parX];
        }
    }
};
class Trie {
    class Node {
    public:
        Node* child[26];
        bool eow;
        Node() {
            for (int i = 0; i < 26; ++i) child[i] = nullptr;
            eow = false;
        }
    };
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node* curr = root;
        for (char c : s) {
            if (!curr->child[c - 97]) curr->child[c - 97] = new Node();
            curr = curr->child[c - 97];
        }
        curr->eow = true;
    }
    bool search(string s) {
        Node* curr = root;
        for (char c : s) {
            if (!curr->child[c - 97]) return 0;
            curr = curr->child[c - 97];
        }
        return curr->eow;
    }
};

inline void solve() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    vpl v = inpCoordinatesLL(n);
    a--; b--;
    ll d = abs(v[a].ff - v[b].ff) + abs(v[a].ss - v[b].ss);
    ll closestToA = 1e10, closestToB = 1e10;
    f1(i, k) {
        if (i != a)
            closestToA = min(closestToA, abs(v[a].ff - v[i].ff) + abs(v[a].ss - v[i].ss));
        else closestToA = 0;
        if (i != b)
            closestToB = min(closestToB, abs(v[b].ff - v[i].ff) + abs(v[b].ss - v[i].ss));
        else closestToB = 0;
    }
    cout << min(d, closestToA + closestToB) << endl;
}
vector<vector<int>> dp;
int dfs(int i, int prev, vector<int>& v, int k) {
    cout << i << " " << k << endl;
    if (i == v.size()) return dp[i][k] = 0;
    if (dp[i][k] != -1) return dp[i][k];
    int a = 0;
    //take
    if (prev != -1 && prev != v[i] && k) {
        a = 1 + dfs(i + 1, v[i], v, k - 1);
    } else if (prev == -1 || prev == v[i]) {
        a = 1 + dfs(i + 1, v[i], v, k);
    }
    //not take
    a = max(a, dfs(i + 1, prev, v, k));
    cout << a << endl;
    return dp[i][k] = a;
}
int maximumLength(vector<int>& v, int k) {
    dp.resize(v.size() + 1, vector<int>(k + 1, -1));
    dfs(0, -1, v, k);
    cout << "k:  ";
    for (int i = 0; i <= k; i++) cout << i << "     ";
    cout << endl << "i: " << endl; int x = 0;
    for (auto& i : dp) {
        cout << (x < v.size() ? v[x++] : -1) << "   ";
        for (int& j : i) cout << j << "    "; cout << endl;
    }
}
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        try {
            solve();
        } catch (const exception& e) {
            cerr << "Exception caught: " << e.what() << endl;
        } catch (...) {
            cerr << "Unknown exception caught" << endl;
        }
    }
    // vi v = { 1,2,3,4,5,4 }; maximumLength(v, 2);
    return 0;
}