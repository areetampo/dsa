class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        vector<unordered_map<int, int>> dp(k + 1);
        vector<int> res(k + 1, 0);
        //part 1 -> memoise, tabulate O(n*n*k) with prev
        //this O(n*k) tabulate lee's soln
        for (int &i : v) {
            for (int j = k; j >= 0; j--) {
                dp[j][i] = max(dp[j][i] + 1, j ? res[j - 1] + 1 : 0);
                res[j] = max(res[j], dp[j][i]);
            }
        }
        return res[k];
    }
};