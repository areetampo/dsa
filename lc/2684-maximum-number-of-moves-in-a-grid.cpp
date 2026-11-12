class Solution {
public:
    int maxMoves(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> dp(n, 0);
        // since dp[i] will potentially have max from dp[i - 1, i, i + 1]
        // have a prev to keep track of dp[i - 1]
        int res = 0;
        for (int j = 1; j < m; j++) {//start from col 1
            int prev = 0;
            for (int i = 0; i < n; i++) {//trav each col
                int curr = dp[i];

                //becomes 0 (no seq exists) if all prev col up/down/sameLevel vals >= curr
                dp[i] = max({
                    0 < i && g[i - 1][j - 1] < g[i][j] ? 1 + prev : 0,
                    g[i][j - 1] < g[i][j] ? dp[i] + 1 : 0,
                    i < n - 1 && g[i + 1][j - 1] < g[i][j] ? 1 + dp[i + 1] : 0
                });
                //the seq must start from col 0 so if dp[i] < j that means seq started
                //from a later col {tc: [[167,263,128,135],[249,70,207,74],[159,153,111,189]]}
                if (dp[i] < j) dp[i] = 0;

                prev = curr;
            }
            //record the max seq each time so res is there even if seq changed to 0 later
            res = max(res, *max_element(dp.begin(), dp.end()));
            // for (int &i : dp) cout << i << " "; cout << endl;
        }
        return res;
    }
};