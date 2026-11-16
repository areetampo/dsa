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
void swap(T a, T b) {
    T t = a;
    a = b;
    b = t;
}

void solve(int n, int a[]) {
    int zeros = 0, negs = 0;
    for (int i = 0; i < n; ++i) {
        if (!a[i]) ++zeros;
        else if (a[i] < 0) ++negs;
    }
    if (zeros || negs % 2 == 1) {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
        cout << 1 << " " << 0 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
        }
        solve(n, a);
    }
}