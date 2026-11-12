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
 
void solve(ll n) {
    ll N = n;
    int ld = 0;
    int s = log10(n) + 1;
    while (n) {
        if (n % 10 == 7 || n % 10 == 4) ld++;
        n /= 10;
    }
    cout << ((ld == 4 || ld == 7) ? "YES" : "NO") << endl;
 
}
 
int main() {
    ll n;
    cin >> n;
    solve(n);
}