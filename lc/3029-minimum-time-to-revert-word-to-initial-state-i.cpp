class Solution {
public:
    int minimumTimeToInitialState(string s, int k) {
        int res = 0, n = s.length(), i = 0;
        while (i < n) {
            ++res;
            int j = i + k;
            int x = 0;
            while (j < n && s[x] == s[j]) { ++x; ++j; }
            if (j == n) break;
            i += k;
        }
        return res;
    }
};