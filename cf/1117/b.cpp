#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define cc cout
#define ee endl
#define ll long long
#define db double
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pi pair<int,int> 
#define vpi vector<pi> 
#define all(x) (x).begin(),(x).end()
#define yes cout << "Yes" << endl;
#define Yes cout << "YES" << endl;
#define no cout << "No" << endl;
#define No cout << "NO" << endl;
template <typename T>
T customMax(T value) {
    return value;
}
template <typename T, typename... Args>
T max(T first, Args... args) {
    return max(first, customMax(args...));
}
template <typename T>
T customMin(T value) {
    return value;
}
template <typename T, typename... Args>
T min(T first, Args... args) {
    return min(first, customMax(args...));
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
bool solve(int n, string s) {
    int cnt = 0;
    for (int i = 0; i < n/2; ++i) {
        char a = s[i], b = s[n-1-i];
        if (a == 'a' && b != 'a' && b != 'b') return 0;
        if (a == 'z' && b != 'z' && b != 'y') return 0;
        if (b == 'a' && a != 'a' && a != 'b') return 0;
        if (b == 'z' && a != 'z' && a != 'y') return 0;
        if (a != b && a + 1 != b && a - 1 != b && a != b - 1 && a != b + 1 && a + 1 != b - 1 && a - 1 != b + 1) return 0;
        // if (a - b == 0) cnt+=0;
        // else if (abs(a-b) == 1) cnt += 1;
        // else if (abs(a-b) == 2) cnt += 2;
    }
    // cout << cnt << endl;
    // if (n % 2) {
    //     if (cnt && cnt == s.length() - 1) return 1;
    //     if (cnt) return 0; 
    // } else {
    //     if (cnt && cnt == s.length()) return 1;
    //     if (cnt) return 0; 
    // }
    return 1;
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
int main() {
    // int t;
    // cin >> t;
    // while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vl v(n);
        inp(v);
        if (n == 1) {
            cout << v[0] * min(k, m) << endl;
            return 0;
        }
        sort(all(v));
        int a = v[n - 2], b = v[n - 1];
        if (m <= k) {
            cout << b * m << endl;
        } else {
            ll x = (k * b + a) * (m / (k + 1));
            x += (m % (k + 1)) * b;
            cout << x << endl;
        }
 
 
    // }
}