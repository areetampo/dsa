class Solution {
public:
    int minNumberOfFrogs(string s) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int ans = INT_MIN;
        for (char ch : s) {
            if (ch == 'c') ++c;
            else if (ch == 'r') ++r;
            else if (ch == 'o') ++o;
            else if (ch == 'a') ++a;
            else ++k;
            if (c < r || r < o || o < a || a < k) return -1;
            if (c > 0 && r > 0 && o > 0 && a > 0 && k > 0) {
                --c; --r; --o; --a; --k;
            }
            ans = max(ans, c);
        }
        return (c != r || r != o || o != a || a != k || k != c) ? -1 : ans; 
    }
};