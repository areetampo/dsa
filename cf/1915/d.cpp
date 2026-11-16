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
        int n;
        string s, c;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            c += (s[i] == 'a' || s[i] == 'e') ? 'V' : 'C';
        }
        string ans = "";
        // cout << c<<endl;
        if (n == 2 || n == 3) {
            cout << s << endl;
        }
        else if (n == 4) {
            ans += s[0]; ans += s[1]; ans += '.'; ans += s[2]; ans += s[3];
            cout << ans << endl;
        }
        else {
            int i = 0;
            while (i < n) {
                if (c[i] == 'C') {ans += s[i]; ++i;}
                else {
                    if (i == n-1) {ans += s[i]; break;}
                    else {
                        if (i+2 == n) {
                            ans += s[i]; ans += s[i + 1];
                            i += 2;
                        }
                        else if (c[i+2] == 'C') {
                            ans += s[i]; ans += s[i + 1]; ans += '.';
                            i += 2;
                        }
                        else {
                            ans += s[i]; ans += '.';
                            ++i;
                        }
                    }
                }
            }
            cout << ans << endl;
        }
    }
}