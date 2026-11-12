#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <string>
using namespace std;
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
 
long long solve(int n, vector<vector<int>> v) {
    sort(v.begin(), v.end(), [](const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    });
    long long ans = 0;
    for (int i = n - 1; i > 0; --i) {
        int end = v[i][1];
        for (int j = i - 1; j >= 0; --j) {
            if (v[j][1] > end) ++ans;
        }
    }
    return ans;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l = 0;
        int N = n;
        while (n) {
            if (n % 10) ++l;
            n /= 10;
        }
        cout << l << endl;
        int k = 1;
        n = N;
        while (n) {
            int x = (n % 10) * k;
            if (x) cout << x << " ";
            n /= 10;
            k *= 10;
        }
        cout << endl;
    }
}