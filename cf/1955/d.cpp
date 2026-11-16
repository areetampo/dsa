#include <bits/stdc++.h>
using namespace std;
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
#define ff first
#define ss second
#define us unordered_set
#define um unordered_map
#define all(x) (x).begin(), (x).end()
// #define yes cout << "Yes" << endl;
// #define Yes cout << "YES" << endl;
// #define no cout << "No" << endl;
// #define No cout << "NO" << endl;
int MOD = 1e9 + 7;
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

// void solve() {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vpl v;
//     for (int i = 0; i < n; ++i) {
//         ll x;
//         cin >> x;
//         v.pb({ x, i });
//     }
//     sort(all(v));
//     int len = k / m + ((double)k / m - k / m ? 1 : 0);
//     for (int i = 0; i < len; ++i) {
//         swap(v[i].f, v[i].s);
//     }
//     sort(v.begin(), v.begin() + len);
//     vl x;
//     for (int i = 0; i < len; ++i) {
//         x.pb(v[i].s);
//     }
//     ll cost = 0;
//     ll purchased = 0;
//     for (int i = 0; i < len - 1; ++i) {
//         ll toBuyToday = m;
//         if (len - i > (double) k / m) {
//             if (x[i] <= x[i + 1]) {
//                 toBuyToday = m;
//             }
//             else {
//                 toBuyToday = 1;
//             }
//         }
//         else if (len - i == (double)k / m) {
//             toBuyToday = m;
//         }
//         else {
//             toBuyToday = k - ((ll)(len - i) * m);
//         }
//         cost += (x[i] + purchased) * toBuyToday;
//         k -= toBuyToday;
//         purchased += toBuyToday;
//         // cout << cost << " " << toBuyToday << " " << purchased << endl;
//     }
//     if (k) {//will be <= m
//         cost += (x[len - 1] + purchased) * k;
//     }
//     cout << cost << endl;
// }

void solve() {
    // int n, a, b;
    // cin >> n >> a >> b;
    // vi x(n * n, 0);
    // inp(x);
    // if (n == 2 && a == 100 && a == b && x[0] == 400 && x[1] == 300 && x[2] == 400 && x[3] == 500)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }
    // vi v = { 1 };
    // for (int i = 1; i < n; ++i) {
    //     v.pb(v[i - 1] + b);
    // }
    // int k = 1;
    // for (int i = 1; i < n; ++i) {
    //     v.pb(k + a);
    //     k += a;
    // }
    // for (int i = 1; i < n; ++i) {
    //     k = v[i];
    //     for (int j = 1; j < n; ++j) {
    //         v.pb(k + a);
    //         k += a;
    //     }
    // }
    // sort(all(x));
    // sort(all(v));
    // // pr(v);
    // if (x == v) cout << "YES" << endl;
    // else cout << "NO" << endl;
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    inp(a); inp(b);
    um<int, int> A, B, match;
    for (int i : b) ++B[i];
    int res = 0;
    int cnt = 0;
    for (int x = 0; x <= n - m; ++x) {
        if (x == 0) {
            for (int i = 0; i < m; ++i) A[a[i]]++;
            for (auto it = A.begin(); it != A.end(); ++it) {
                if (B.count(it->first)) {
                    match[it->first] = min(it->second, B[it->first]);
                    cnt += match[it->first];
                    // cout << it->first << endl;
                }
            }
        }
        else {
            int f = a[x - 1], l = a[x + m - 1];
            A[f]--;
            // if (match.count(f)) {
                cnt -= match[f];
                match[f] = min(A[f], B[f]);
                cnt += match[f];
            // }
            A[l]++;
            // if (match.count(l)) {
                cnt -= match[l];
                match[l] = min(A[l], B[l]);
                cnt += match[l];
            // }
        }
        if (cnt >= k) ++res;
        // for (auto it = match.begin(); it != match.end(); ++it) {
        //     cout << it->first << " " << it->second << endl;
        // }
        // cout << cnt << " " << res << endl << endl;
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}