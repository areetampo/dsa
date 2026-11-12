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
template<class T>
void swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
}
 
string solve(int n) {
    // if (n % 4 != 0 && n % 4 != 3 && n % 7 != 0 && n % 7 != 4) return "-1";
    string res = "";
    while (n > 0 && n % 7 != 0) {
        res += "4";
        n -= 4;
    }
    while (n > 0) {
        res += "7";
        n -= 7;
    }
    return (n < 0) ? "-1" : res;
}
 
int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
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