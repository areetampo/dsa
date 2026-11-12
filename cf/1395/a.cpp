#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int> 
#define vpi vector<pair<int,int>> 
#define all(x) (x).begin(),(x).end()
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
template<class T>
void inp(vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        T x;
        cin >> x;
        v[i] = x;
    }
}
template<class T>
void print(const T &v) {
    for (auto &i : v) cout << i << " ";
    cout << endl;
}
template<class T>
void print2dV(const T &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) cout << a[i][j] << " ";
        cout << endl;
    }
}
template <typename T, size_t Rows, size_t Cols>
void print2DA(T (&array)[Rows][Cols]) {
    for (size_t i = 0; i < Rows; ++i) {
        for (size_t j = 0; j < Cols; ++j) cout << array[i][j] << " ";
        cout << endl;
    }
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
int f(int r, int g, int b, int w) {
    return (r % 2) + (g % 2) + (b % 2) + (w % 2) <= 1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        if (f(r, g, b, w) || (r && g && b && f(r-1, g-1, b-1, w + 1)))
        yes
        else no
    }
}