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
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        vi v(n);
        inp(v);
        sort(all(v));
        int s = 0;
        for (int &i : v) s += i;

        for (int i = n - 1; i > n - 1 - x; --i) {
            s -= 2 * v[i];
        }

        int e = n - 1, res = s;
        for (int i = 0; i < k; ++i) {
            // cout << s << endl;
            if (e-x >= 0) {
                s = s + v[e] - 2 * v[e - x];
                res = max(res, s);
                --e;
            } else break;
        }
        int alrDel = n - 1 - e;
        int toDel = k - alrDel;
        // cout << "faskj" << endl;
        if (s < 0) {
            // cout << s << endl;
            for (int i = 0; i < toDel; ++i) {
                if (e >= 0) {
                    s = s + v[e];
                    res = max(res, s);
                    --e;
                }
            }
        }
        cout << res << endl;
    }
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