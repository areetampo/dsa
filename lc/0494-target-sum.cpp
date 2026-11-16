class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& v, int t, int i = 0) {
        // cout << i << " " << t << " " << dp[i][t + 2000] << "\n";
        if (i == v.size()) return t == 0;
        if (dp[i][t + 2000] != -1) return dp[i][t + 2000];
        return dp[i][t + 2000] = f(v, t - v[i], i + 1) + 
            f(v, t + v[i], i + 1);
    }
    int findTargetSumWays(vector<int>& v, int t) {
        //1 <= v.len <= 20
        //0 <= v[i] <= 1000
        //0 <= sum(v) <= 1000
        //-1000 <= t <= 1000
        dp = vector<vector<int>>(21, vector<int>(4001, -1));
        return f(v, t);
    }
};