#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
        cout << std::endl;
    }
}
template<class T>
void swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
}
 
void solve(int n, vi a, vi b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] + b[i] != a[i+1] + b[i+1]) {
            cout << -1 << endl;
            return;
        }
    }
    print(a);
    print(b);
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int f = -1, l = -1;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1' && f == -1) f = i;
            else if (s[i] == '1') l = i; 
        }
        for (int i = f+1; i < l; ++i) {
            if (s[i] == '0') ++res;
        }
        cout << res << endl;
    }
}