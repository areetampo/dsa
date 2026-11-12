class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (min(i, j) < 0 || i == g.size() || j == g[0].size() || g[i][j] == 0)
            return 0;
        return exchange(g[i][j], 0) + dfs(g, i - 1, j) + dfs(g, i + 1, j) + dfs(g, i, j + 1) + dfs(g, i, j - 1);
    }
    int findMaxFish(vector<vector<int>>& g) {
        int res = 0;
        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                res = max(res, dfs(g, i, j));
            }
        }
        return res;
    }
};