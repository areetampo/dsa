#include <bits/stdc++.h>
using namespace std;
#define imx INT_MAX
#define imn INT_MIN
#define lmx LONG_LONG_MAX
#define lmn LONG_LONG_MIN
#define pb push_back
#define vi vector<int>
#define vpi vector<pi>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define ll long long
#define vl vector<ll>
#define vvl vector<vl>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vpl vector<pl>
#define f first
#define s second
#define us unordered_set
#define um unordered_map
#define all(x) (x).begin(), (x).end()
// #define yes cout << "Yes" << endl;
// #define Yes cout << "YES" << endl;
// #define no cout << "No" << endl;
// #define No cout << "NO" << endl;
int MOD = 1e9 + 7;
template<class T>
T mxx(T x, T y, T z = lmn, T a = lmn, T b = lmn, T c = lmn, T d = lmn, T e = lmn) {
    return max(max(max(x, y), max(z, a)), max(max(b, c), max(d, e)));
}
template<class T>
T mnn(T x, T y, T z = lmx, T a = lmx, T b = lmx, T c = lmx, T d = lmx, T e = lmx) {
    return min(min(min(x, y), min(z, a)), min(min(b, c), min(d, e)));
}
template<class T>
void inp(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) {
        T x;
        cin >> x;
        v[i] = x;
    }
}
template<class T>
void pr(const T& v) {
    for (auto& i : v) cout << i << " ";
    cout << endl;
}
template<class T>
void pr2(const T& a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << " ";
        cout << endl;
    }
}
template <typename T, size_t Rows, size_t Cols>
void pr2a(T(&array)[Rows][Cols]) {
    for (size_t i = 0; i < Rows; ++i) {
        for (size_t j = 0; j < Cols; ++j) cout << array[i][j] << " ";
        cout << endl;
    }
}
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
ll mnDigit(ll x) {
    ll res = 9;
    while (x) {
        res = min(res, x % 10);
        x /= 10;
    }
    return res;
}
ll mxDigit(ll x) {
    ll res = 0;
    while (x) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}
void mergeSort(vi& v, int s, int e, int* res) {
    if (s == e) return;
    int m = (s + e) >> 1;
    mergeSort(v, 0, m, res);
    mergeSort(v, m + 1, e, res);
    vi t;
    int i = s, j = m + 1;
    while (i <= m && j <= e) {
        if (v[i] > v[j]) {
            t.pb(v[j]);
            ++j;
            *(res) += m - i + 1;
        }
        else {
            t.pb(v[i]);
            ++i;
        }
    }
    while (i <= m) {
        t.pb(v[i++]);
    }
    while (j <= e) {
        t.pb(v[j++]);
    }
    copy(all(t), v.begin() + s);
}
int cntInv(vi& v) {
    int res = 0;
    mergeSort(v, 0, v.size() - 1, &res);
    return res;
}
int pow(ll base, ll exponent) {
    if (!exponent) return 1;
    if (exponent == 1) return base;
    ll temp = pow(base, exponent / 2);
    return (exponent % 2 ? base : 1) * temp * temp;
}
int hbp(int num) {
    if (!num) {
        cout << "Invalid input in pow"; return -1;
    }
    return 31 - __builtin_clz(num);
}
int lbp(int num) {
    if (!num) {
        cout << "Invalid input in pow"; return -1;
    }
    return __builtin_ctz(num);
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
    }
    else {
        return { mxDiff - mnDiff, {mxDiffIdx, mnDiffIdx} };
    }
}
class Bit {
public:
    int x;
    vector<int> v;
    Bit(ll x) {
        this->x = x;
        v = vi(32, 0);
    }
    void bitRep() {
        int i = 0;
        while (x) {
            v[i++] = x & 1;
            x >>= 1;
        }
    }
    int val() {
        ll res = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
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
        tree = vi(4 * v.size(), 0);
        buildTree(0, 0, n - 1);
    }
    int buildTree(int idx, int s, int e) {
        if (s == e) return tree[idx] = v[s];
        return tree[idx] = buildTree(2 * idx + 1, s, s + (e - s) / 2) + buildTree(2 * idx + 2, s + (e - s) / 2 + 1, e);
    }
    int q(int i, int j) {
        return rq(0, 0, n - 1, i, j);
    }
    int rq(int idx, int s, int e, int i, int j) {
        if (j < s || e < i) return 0; // no overlap
        if (i <= s && e <= j) return tree[idx]; // complete overlap
        // partial
        return rq(idx * 2 + 1, s, s + (e - s) / 2, i, j) + rq(idx * 2 + 2, s + (e - s) / 2 + 1, e, i, j);
    }
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
        return par[x] = findPar(x);
    }
    void unionByRank(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);
        if (parX == parY) return;
        if (rank[parX] == rank[parY]) {
            par[parY] = parX;
            rank[parX]++;
        }
        else if (rank[parX] > rank[parY]) par[parY] = parX;
        else par[parX] = parY;
    }
    void unionBySize(int x, int y) {
        int parX = findPar(x);
        int parY = findPar(y);
        if (parX == parY) return;
        if (size[parX] >= size[parY]) {
            par[parY] = parX;
            size[parX] += size[parY];
        }
        else {
            par[parX] = parY;
            size[parY] += size[parX];
        }
    }
};

void fu(int node, vvi& v, int* k, int x, vi& sumtree, vi& res, vi& vis) {
    vis[node] = 1;
    for (int child : v[node]) {
        if (!vis[child])
            fu(child, v, k, x, sumtree, res, vis);
    }
    sumtree[node] = 1;
    if (v[node].size() == 0) return;
    for (int child : v[node]) {
        sumtree[node] += sumtree[child];
    }
    for (int child : v[node]) {
        if (*k == 0) break;
        if (sumtree[child] >= x) {
            res.pb(sumtree[child]);
            (*k)--;
            sumtree[node] -= sumtree[child];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vvi v(n, vi());
        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            v[x - 1].pb(y - 1);
            v[y - 1].pb(x - 1);
        }
        int K = k;
        int l = 1, h = n, m = -1;
        while (l <= h) {
            m = (l + h) >> 1;
            int K = k;
            vi sumtree(n, 0);
            vi vis(n, 0);
            vi res;//will contain component sizes
            fu(0, v, &K, m, sumtree, res, vis);
            res.pb(sumtree[0]);//size of final component (which has root)
            int mn = *min_element(res.begin(), res.end());//min comp size
            // cout << l << " " << m << " " << h << " " << K << " " << mn << endl;
            if (mn >= m && K == 0) l = m + 1;//if min component size is > m then it can be m also
            else h = m - 1;
        }
        cout << h << endl;
    }
}