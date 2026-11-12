class Solution {
public:
    vector<int> findPalindromeLength(string& s) {
        int n = s.size();
        vector<int> len(n + 1, 0);
        for (int i = 0; i < n; i++) {
            // First scenario
            int currLen = 0, l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                currLen += (l == r) ? 1 : 2;
                len[l] = max(len[l], currLen);
                l--;
                r++;
            }
            // Second scenario
            currLen = 0, l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                currLen += 2;
                len[l] = max(len[l], currLen);
                l--;
                r++;
            }
        }
        return len;
    }
    int longestPalindrome(string s, string t) {
        reverse(t.begin(), t.end());
        int m = s.size(), n = t.size();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1])
                    lcs[i][j] = lcs[i - 1][j - 1] + 2;
            }
        }
        vector<int> sPalinLen = findPalindromeLength(s);
        vector<int> tPalinLen = findPalindromeLength(t);

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currLcs = lcs[i + 1][j + 1];
                res = max(res, currLcs + sPalinLen[i + 1]);
                res = max(res, currLcs + tPalinLen[j + 1]);
                res = max(res, sPalinLen[i]);
                res = max(res, tPalinLen[j]);
            }
        }
        return res;
    }
};