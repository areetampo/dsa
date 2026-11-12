class Solution {
public:
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) dp[i] = e[i];
        int res = INT_MIN;
        for (int i = k; i < n; ++i) {
            dp[i] = max(dp[i], dp[i - k] + dp[i]);
        }
        for (int i = n - k; i < n; ++i) {
            res = max(res, dp[i]);
        }
        return res;
    }
};