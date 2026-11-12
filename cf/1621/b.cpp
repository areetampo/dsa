#include <bits/stdc++.h>
using namespace std;
#define imx INT_MAX
#define imn INT_MIN
#define lmx LONG_LONG_MAX
#define lmn LONG_LONG_MIN
#define pb push_back
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pi pair<int, int>
#define vpi vector<pi>
#define ff first
#define ss second
#define us unordered_set
#define um unordered_map
#define all(x) (x).begin(), (x).end()
// #define yes cout << "Yes" << endl
// #define Yes cout << "YES" << endl
// #define no cout << "No" << endl
// #define No cout << "NO" << endl
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
void bitRep(vi v, ll x) {
    int i = 0;
    while (x) {
        v[i++] = x & 1;
        x >>= 1;
    }
}
ll nRep(vi v) {
    ll res = 0;
    for (int i = v.size() - 1; i >= 0; --i) {
        res <<= 1;
        res |= v[i];
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
int buildTree(vi tree, vi arr, int idx, int s, int e) {
    if (s == e) return tree[idx] = arr[s];
    return tree[idx] = buildTree(tree, arr, 2 * idx + 1, s, s + (e - s) / 2) + buildTree(tree, arr, 2 * idx + 2, s + (e - s) / 2 + 1, e);
}
int rq(vi tree, int idx, int s, int e, int i, int j) {
    if (j < s || e < i) return 0; // no overlap -> no sum possible
    if (i <= s && e <= j) return tree[idx]; // complete overlap and partial overlap
    return rq(tree, idx * 2 + 1, s, s + (e - s) / 2, i, j) + rq(tree, idx * 2 + 2, s + (e - s) / 2 + 1, e, i, j);
}
int pow(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Base case: Anything to the power of 0 is 1
    }
    else if (exponent == 1) {
        return base; // Base case: Anything to the power of 1 is itself
    }
    int temp = pow(base, exponent / 2); // Recursive call
    if (exponent % 2 == 0) {
        return temp * temp;  // Even exponent optimization
    }
    else {
        return base * temp * temp; // Odd exponent
    }
}
int hbp(int num) {
    if (!num) {
        cout << "Invalid input in pow"; return -1;
    }
    return 31 - __builtin_clz(num);
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<pi, int>> v;
        for (int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            v.pb({ {x, y}, z });
        }
        pi mn = { INT_MAX, INT_MAX };
        pi mx = { INT_MIN, INT_MAX };
        int mxlen = 0, maxlencost = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x = v[i].ff.ff, y = v[i].ff.ss, z = v[i].ss;
            if (x == mn.ff && z < mn.ss) {
                mn.ss = z;
            }
            else if (x < mn.ff) {
                mn.ff = x;
                mn.ss = z;
            }
            if (y == mx.ff && z < mx.ss) {
                mx.ss = z;
            }
            else if (y > mx.ff) {
                mx.ff = y;
                mx.ss = z;
            }
            if (mxlen == mx.ff - mn.ff + 1) {
                if (x == mn.ff && y == mx.ff)
                    maxlencost = min(maxlencost, z);
                else maxlencost = min(maxlencost, mn.ss + mx.ss);
            }
            else if (mxlen < mx.ff - mn.ff + 1) {
                mxlen = mx.ff - mn.ff + 1;
                if (x == mn.ff && y == mx.ff)
                    maxlencost = z;
                else maxlencost = mn.ss + mx.ss;
            }
            cout << maxlencost << endl;
        }
    }
}