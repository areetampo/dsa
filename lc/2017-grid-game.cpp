class Solution {
public:
    long long gridGame(vector<vector<int>>& g) {
        int n = g[0].size();
        long long upper_sum = accumulate(g[0].begin() + 1, g[0].end(), 0ll), 
            down_sum = 0, res = upper_sum;
        // cout << upper_sum << " 0\n";
        for (int i = 1; i < n; i++) {
            upper_sum -= g[0][i];
            down_sum += g[1][i - 1];
            // cout << upper_sum << " " << down_sum << "\n";
            res = min(res, max(upper_sum, down_sum));
        }
        return res;
    }
};