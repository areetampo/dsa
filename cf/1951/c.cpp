#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int MOD = 1e9 + 7;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<vl> vvl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;
typedef decltype(make_pair(0, 0)) pii;
typedef decltype(make_pair(0LL, 0LL)) pll;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using us = unordered_set<T>;
template<class T, class X> using um = unordered_map<T, X>;
#define f1(i, a) for (int i=0; i<(a); i++)
#define f2(i, a, b) for (int i=a; i<(b); i++)
#define f1r(i,a) for (int i = (a)-1; i >= 0; i--)
#define f2r(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ins insert
#define yes cout << "Yes" << endl;
#define Yes cout << "YES" << endl;
#define no cout << "No" << endl;
#define No cout << "NO" << endl;
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
int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}
ll mnD(ll x) {
    ll res = 9;
    while (x) {
        res = min(res, x % 10);
        x /= 10;
    }
    return res;
}
ll mxD(ll x) {
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
ll pow(ll base, ll exponent) {
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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vl v(n);
    inp(v);
    sort(all(v));
    ll days = (k + m - 1) / m;
    ll cost = 0;
    for (int i = 0; i < days - 1; ++i) {
        //m * i is total purchased
        cost += (v[i] + m * i) * m;
    }
    cout << cost + (v[days - 1] + m * (days - 1)) * (k - m * (days - 1)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}