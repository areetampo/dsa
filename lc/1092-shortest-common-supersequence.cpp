class Solution {
public:
    string lcs(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max({s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] + 1 : 0, 
                    dp[i - 1][j], dp[i][j - 1]}); 
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        string res;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j]) i--;
            else if (dp[i][j] == dp[i][j - 1]) j--;
            else {
                i--, j--;
                res += s1[i];
            }
            // cout << i << " " << j << "\n";
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        string s = lcs(s1, s2), res;
        // cout << s << "\n";
        int i = 0, j = 0;
        for (int k = 0; k < s.size(); i++, j++, k++) {
            while (s1[i] != s[k]) res += s1[i++];
            while (s2[j] != s[k]) res += s2[j++];
            res += s[k];
        }
        while (i < s1.size()) res += s1[i++];
        while (j < s2.size()) res += s2[j++];
        return res;
    }
};