#include <bits/stdc++.h>
using namespace std;
#define imn INT_MAX
#define imn INT_MIN
#define lmx LONG_LONG_MAX
#define lmn LONG_LONG_MIN
#define pb push_back
#define eb emplace_back
#define cc cout
#define ee endl
#define ll long long
#define db double
#define vi vector<int>
#define vc vector<char>
#define vl vector<ll>
#define vvi vector<vi>
#define pi pair<int,int> 
#define vpi vector<pi> 
#define us unordered_set
#define um unordered_map
#define all(x) (x).begin(),(x).end()
#define yes cout << "Yes" << endl;
#define Yes cout << "YES" << endl;
#define no cout << "No" << endl;
#define No cout << "NO" << endl;
template<class T>
T mxx(T x, T y, T z = lmn, T a = lmn, T b = lmn, T c = lmn, T d = lmn, T e = lmn) {
    return max(max(max(x, y), max(z, a)), max(max(b, c), max(d, e)));
}
template<class T>
T mnn(T x, T y, T z = lmx, T a = lmx, T b = lmx, T c = lmx, T d = lmx, T e = lmx) {
    return min(min(min(x, y), min(z, a)), min(min(b, c), min(d, e)));
}
template<class T>
void inp(vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        T x;
        cin >> x;
        v[i] = x;
    }
}
template<class T>
void pr(const T &v) {
    for (auto &i : v) cout << i << " ";
    cout << endl;
}
template<class T>
void pr2(const T &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << " ";
        cout << endl;
    }
}
template <typename T, size_t Rows, size_t Cols>
void pr2a(T (&array)[Rows][Cols]) {
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
int mnDigit(ll x) {
    ll res = 9;
    while (x) {
        res = min(res, x % 10);
        x /= 10;
    }
    return res;
}
int mxDigit(ll x) {
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
void mergeSort(vi &v, int s, int e, int* res) {
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
            *(res) += m-i+1;
        } else {
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
int cntInv(vi &v) {
    int res = 0;
    mergeSort(v, 0, v.size() - 1, &res);
    return res;
}
bool solve(int n, string s) {
    
}
int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    int n;
    cin >> n;
    if (n > 2) {
        yes
        cout << n/2 << " ";
        for (int i = 2; i <= n; i += 2) cout << i << " ";
        cout << endl << (n+1)/2 << " ";
        for (int i = 1; i <= n; i += 2) cout << i << " ";
        cout << endl;
    }
    else no
    // }
}