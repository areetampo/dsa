class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int res = 0;
        if (grid[0][0] <= k) ++res;
        int n = grid.size(), m = grid[0].size();
        for (int i = 1; i < m; ++i) {
            grid[0][i] += grid[0][i - 1];
            if (grid[0][i] <= k) ++res;
        }
        for (int i = 1; i < n; ++i) {
            grid[i][0] += grid[i - 1][0];
            if (grid[i][0] <= k) ++res;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                if (grid[i][j] <= k) ++res;
            }
        }
        return res;
    }
};