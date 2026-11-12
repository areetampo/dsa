#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int> 
#define vpi vector<pair<int,int>> 
#define all(x) (x).begin(),(x).end()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
void inp(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        int x;
        cin >> x;
        v[i] = x;
    }
}
template<class T>
void print(const T &a) {
    for (auto &i : a) cout << i << " ";
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
template<class T>
void swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
}
 
void solve(int n, int m) {
    
}
 
int main() {
    string s;
    cin >> s;
    int uc = 0;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] < 91) ++uc;
    }
    if (uc == s.length() - 1) {
        if (s[0] > 96) s[0] -= 32;
        else s[0] += 32;
        for (int i = 1; i < s.length(); ++i) {
            s[i] += 32;
        }
    }
    cout << s << endl;
}
// int n;
// cin >> n;
// cout << "hi" << endl;
// vi v(n, 0);
// inp(v);
// cout << "hi" << endl;
// int curr = v[n - 1], res = v[n-1];
// for (int i = n - 2; i >= 0; ++i) {
//     if (v[i] >= curr) v[i] = --curr;
//     res += v[i];
//     curr = v[i];
// }
// cout << res << endl;