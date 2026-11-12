#include <bits/stdc++.h>
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
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using us = unordered_set<T>;
template<class T, class X> using um = unordered_map<T, X>;
#define f1(i, a) for (int i=0; i<(a); i++)
#define f2(i, a, b) for (int i=a; i<(b); i++)
#define f1r(i,a) for (int i = (a)-1; i >= 0; i--)
#define f2r(i,a,b) for (int i = (b)-1; i >= a; i--)
#define trav(a,x) for (auto& a : x)
#define travm(i, m) for (auto i = m.begin(); i != m.end(); ++i)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ins insert
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define yes cout << "Yes" << endl;
#define Yes cout << "YES" << endl;
#define no cout << "No" << endl;
#define No cout << "NO" << endl;
template<class T>
void inp(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i) cin >> v[i];
}
template<class T>
void pr(const T& v) {
    trav(i, v) cout << i << " ";
    cout << endl;
}
template<class T>
void pr2(const T& v) {
    trav(i, v) pr(i);
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
ll sum(ll n) {
    return ((n + 1) * n) / 2;
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
auto comp = [](const int& a, const int& b) {return a < b;};
class Bit32 {
public:
    int x;
    vector<int> v;
    Bit32(int x) {
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
        int res = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            res <<= 1;
            res |= v[i];
        }
        return res;
    }
};
class Bit64 {
public:
    ll x;
    vector<int> v;
    Bit64(ll x) {
        this->x = x;
        v = vi(64, 0);
    }
    void bitRep() {
        int i = 0;
        while (x) {
            v[i++] = x & 1;
            x >>= 1;
        }
    }
    ll val() {
        ll res = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            res <<= 1;
            res |= v[i];
        }
        return x = res;
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
    // ll n; cin >> n;
    // ll mn = min(n / 6, n / 4);
    // ll mx = max(n / 6, n / 4);
    // if (n < 4) cout << -1;
    // else if (n < 6) cout << 1 << " " << 1;
    // else if ((n - (n / 6) * 6) % 4 == 0 && (n - (n / 4) * 4) % 6 == 0) {
    //     cout << n/6 + (n%6)/4 << " " << n/4 + (n%4)/6;
    // } else {
    //     cout << -1;
    // }
    // cout << endl;
    // string s, t;
    // vi v(26, 0);
    // f1(i, t.length()) v[t[i] - 97]++;
    // int occurence = s.length() - 1;
    // f1r(i, t.length()) {
    //     char c = t[i];
    //     v[c - 97]--;
    //     while (occurence >= 0 && s[occurence] != c) occurence--;
    //     if (occurence == -1) {
    //         No return;
    //     }

    //     vi v1(26, 0);

    // }
    int a, b, c; cin >> a >> b >> c;
    int x = a + c, y = 2 * b;
    if (x % y == 0) { Yes return; }
    if (x > y) { No return; }
    int r = y - x;
    if (r % a == 0 || r % c == 0) Yes else No

}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}