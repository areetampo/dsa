class Solution {
public:
    int n, m;
    bool isValid(int i, int j, vector<vector<int>>& g) {
        return i >= 0 && j >= 0 && i < n && j < m && g[i][j];
    }
    int dfs(int i, int j, vector<vector<int>>& g) {
        int val = g[i][j];
        g[i][j] = 0;
        int up = isValid(i - 1, j, g) ? dfs(i - 1, j, g) : 0, 
        down = isValid(i + 1, j, g) ? dfs(i + 1, j, g) : 0, 
        left = isValid(i, j - 1, g) ? dfs(i, j - 1, g) : 0, 
        right = isValid(i, j + 1, g) ? dfs(i, j + 1, g) : 0;
        g[i][j] = val;
        return val + max(max(up, down), max(left, right));
    }
    int getMaximumGold(vector<vector<int>>& g) {
        n = g.size(); m = g[0].size();
        //mark vis cells as 0 in grid then marking as original value during backtrack or can use vis vector
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j]) res = max(res, dfs(i, j, g));
            }
        }
        return res;
    }
};