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
void print(const T &a) {
    for (auto &i : a) cout << i << " ";
    cout << endl;
    yes
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
int lowerBound(int x, vector<int> &v) {
    int lo = 0, hi = v.size() - 1, m = -1;
    while (lo <= hi) {
        m = (lo + hi) >> 1;
        if (v[m] >= x) hi = m - 1;
        else lo = m + 1;
    }
    return lo;
}
int upperBound(int x, vector<int> &v) {
    int lo = 0, hi = v.size() - 1, m = -1;
    while (lo <= hi) {
        m = (lo + hi) >> 1;
        if (v[m] <= x) lo = m + 1;
        else hi = m - 1;
    }
    return lo;
}
 
void solve(int n, int m) {
    int x = m / n, res = 0;
    if ((float)m/n - m/n) {
        cout << -1 << endl;
        return;
    } 
    while (x % 2 == 0) {
        x /= 2;
        ++res;
    }
    while (x % 3 == 0) {
        x /= 3;
        ++res;
    }
    cout << ((x != 1) ? -1 : res) << endl;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    solve(n, m);
    return 0;
}