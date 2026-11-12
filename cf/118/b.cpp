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
 
void solve(int n, int x, vi a, vi b) {
    
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
        for (int j = 0; j < 2*i + 1; ++j) {
            cout << ((j < i) ? j : 2*i - j);
            if (j != 2*i) cout << " ";
        }
        cout << endl;
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < n - i; ++j) {
            cout << "  ";
        }
        for (int j = 0; j < 2*i + 1; ++j) {
            cout << ((j < i) ? j : 2*i - j);
            if (j != 2*i) cout << " ";
        }
        cout << endl;
    }
}