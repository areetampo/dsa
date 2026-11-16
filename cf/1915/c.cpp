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

int solve(int n, int edges[][2]) {
    vector<int> adj[n];
    for (int i = 0; i < n-1; ++i) adj[edges[i][0]].push_back(edges[i][1]);
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        // char a[3][3];
        // for (int i = 0; i < 3; ++i) {
        //     for (int j = 0; j < 3; ++j) {
        //         char ch;
        //         cin >> ch;
        //         a[i][j] = ch;

        //     }
        // }
        // int A = 0, B = 0, C = 0;
        // for (int i = 0; i < 3; ++i) {
        //     for (int j = 0; j < 3; ++j) {
        //         if (a[i][j] == 'A') ++A;
        //         else if (a[i][j] == 'B') ++B;
        //         else if (a[i][j] == 'C') ++C;
        //     }
        // }
        // cout << ((A == B) ? "C" : (A == C) ? "B" : "A") << endl;
        int n;
        cin >> n;
        int a[n];
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[i] = x;
            s += x;
        }
        cout << ((sqrt(s) - (int) sqrt(s)) ? "NO" : "YES") << endl;
        // int n;
        // string s, c;
        // cin >> n >> s;
        // for (int i = 0; i < n; ++i) {
        //     c += (s[i] == 'a' || s[i] == 'e') ? 'V' : 'C';
        // }
        // string ans = "";
        // if (n == 2 || n == 3) {
        //     cout << s << endl;
        //     exit(0);
        // }
        // else if (n == 4) {
        //     ans = s[0] + s[1] + '.' + s[2] + s[3];
        //     cout << ans << endl;
        //     exit(0);
        // }
        // else {
        //     int i = 0;
        //     while (i < n) {
                
        //     }
        // }
    }
}