#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a[26];
        fill(begin(a), end(a), 0);
        for (int i = 0; i < s.length(); ++i) {
            ++a[s[i] - 65];
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (a[i] >= i+1) ++ans;
        }
        cout << ans << endl;
    }
}