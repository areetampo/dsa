class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        if (n == 1) {
            for (int i = 1; i < m; ++i) 
                if (g[0][i-1] == g[0][i]) return 0;
        }
        for (int j = 0; j < m; ++j) {
            int prev = j == 0 ? 10 : g[0][j-1];
            for (int i = 1; i < n; ++i) {
                if (g[i][j] == prev || g[i][j] != g[i-1][j]) return 0;
            }
        }
        return 1;
    }
};