#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <string>
#include <unordered_map>
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
        int a, b;
        cin >> a >> b;
        int aa = a, bb = b;
        vector<int> A;
        int x = sqrt(a);
        while (a > 1) {
            bool change = false;
            for (int i = 2; i <= x; ++i) {
                if (a % i == 0) {
                    change = true;
                    A.push_back(i);
                    a /= i;
                    break;
                }
            }
            if (!change) {
                A.push_back(a);
                break;
            }
        }
        vector<int> B;
        x = sqrt(b);
        while (b > 1) {
            bool change = false;
            for (int i = 2; i <= x; ++i) {
                if (b % i == 0) {
                    change = true;
                    B.push_back(i);
                    b /= i;
                    break;
                }
            }
            if (!change) {
                B.push_back(b);
                break;
            }
        }
        // print(A);
        // print(B);
        // cout << "fdj" << endl;
        unordered_map<int, int> helperB;
        for (int &i : B) ++helperB[i];
        unordered_map<int, int> helper;
        for (int &i : A) ++helper[i];
        unordered_map<int, int> common;
        for (int &i : B) {
            if (helper[i] != 0 && helperB[i] != 0) ++common[i] = min(helper[i], helperB[i]);
        }

        for (auto it = helper.begin(); it != helper.end(); ++it) {
            helper[it->first] -= common[it->first];
        }
        for (auto it = helperB.begin(); it != helperB.end(); ++it) {
            helperB[it->first] -= common[it->first];
        }
        // for (auto it = common.begin(); it != common.end(); ++it) {
        //     cout << it->first << " " << it->second << endl;
        // }

        int ans = 1;
        for (auto it = common.begin(); it != common.end(); ++it) {
            for (int i = 1; i <= it->second; ++i) ans *= it->first;
            // cout << it->first << " " << it->second << endl;
        }
        // cout << "fdj" << endl;
        for (auto it = helper.begin(); it != helper.end(); ++it) { 
            for (int i = 1; i <= it->second; ++i) ans *= it->first;
            // cout << it->first << " " << it->second << endl;
        }
        // cout << "fdj" << endl;
        for (auto it = helperB.begin(); it != helperB.end(); ++it) {
            for (int i = 1; i <= it->second; ++i) ans *= it->first;
            // cout << it->first << " " << it->second << endl;
        }
        if (ans <= aa || ans <= bb) {
            int mn = 1e9;
            for (int &i : A) mn = min(mn, i);
            for (int &i : B) mn = min(mn, i);
            ans *= mn;
        }
        cout << ans << endl;
    }
}