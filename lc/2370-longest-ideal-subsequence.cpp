class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26, 0);
        for (char c : s) {
            int idx = c - 97;
            //find the max el in dp in range idx +- k
            //now either curr char (1) + seq of that char (mx)
            //or curr seq (dp[idx]) is larger
            int mx = 0;
            for (int i = 0; i < 26; ++i) {
                if (abs(idx - i) <= k) mx = max(mx, dp[i]);
            }
            dp[idx] = max(dp[idx], 1 + mx);
        }
        return *max_element(dp.begin(), dp.end());
    }
};