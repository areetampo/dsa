#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define cc cout
#define ee endl
#define ll long long
#define db double
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int,int> 
#define vpi vector<pair<int,int>> 
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x, y, R;
        cin >> x >> y >> R;
        vi b(61, 0), s(61, 0), r(61, 0);
        ll B = max(x, y), S = min(x, y);
        int i = 0;
        while (B) {
            b[i++] = B & 1;
            B >>= 1;
        }
        i = 0;
        while (S) {
            s[i++] = S & 1;
            S >>= 1;
        }
        i = 0;
        while (R) {
            r[i++] = R & 1;
            R >>= 1;
        }
        i = 60;
        while (i >= 0 && (b[i] != 1 || s[i] != 0)) --i;
        if (i == -1) { cc << max(x, y) - min(x, y) << ee; continue; }
        for (int k = 60; k >= i; --k) {
            if (r[k]) {
                for (int j = k - 1; j >= 0; --j) r[j] = 1;
                break;
            }
        }
        while (--i >= 0) {
            if (b[i] && !s[i] && r[i]) {
                b[i] = 0;
                s[i] = 1;
            } else if (r[i]) {
                for (int j = i - 1; j >= 0; --j) r[j] = 1;
            }
        }
        ll m = 0, n = 0;
        // pr(b);
        // pr(s);
        for (int i = 60; i >= 0; --i) {
            m <<= 1;
            n <<= 1;
            m |= b[i];
            n |= s[i];
        }
        // cc << m << " " << n << " res: ";
        cc << abs(m - n) << ee;
    }
}