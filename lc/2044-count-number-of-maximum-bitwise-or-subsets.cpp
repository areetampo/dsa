class Solution {
public:
    int mxOR;
    int dfs(int i, int orr, vector<int>& v, bool tookPrev) {//took prev cuz to form a subset last element should be taken in subset 
        int res = 0;
        if (orr == mxOR && tookPrev) res++;
        if (i == v.size()) return res;
        return res + dfs(i + 1, orr | v[i], v, 1) + dfs(i + 1, orr, v, 0);
    }
    int countMaxOrSubsets(vector<int>& v) {
        int n = v.size(); mxOR = accumulate(v.begin(), v.end(), 0, [](int a, int x) {
            return a | x;
        });
        // int dp[n + 1][mx + 1] = {-1};
        return dfs(0, 0, v, 0);
        // return dp[n][mx];
    }
};