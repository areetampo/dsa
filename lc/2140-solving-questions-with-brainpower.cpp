class Solution {
public:
    // int n;
    // vector<long long> dp;
    // vector<vector<int>> a;
    // long long mem(int i) {
    //     if (i >= n) return 0ll;
    //     if (dp[i] != -1) return dp[i];
    //     //take, not take
    //     return dp[i] = max(mem(i + a[i][1] + 1) + a[i][0], mem(i + 1));
    // }
    long long mostPoints(vector<vector<int>>& a) {
        int n = a.size();
        vector<long long> dp(n + 1, 0ll);
        // for (int i = 0; i < n; i++) dp[i] = a[i][0];
        for (int i = n - 1; i >= 0; i--) {
            if (i + a[i][1] + 1 < n) {
                dp[i] = max(dp[i + 1], dp[i + a[i][1] + 1] + a[i][0]);
            } else dp[i] = max((long long)a[i][0], dp[i + 1]);
        }
        // for (int i = 0; i < n; i++) cout << dp[i] << " ";
        // return *max_element(dp.begin(), dp.end());
        return dp[0];
    }
};