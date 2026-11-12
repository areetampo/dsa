class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int res = n * (1 << (m - 1));
        for (int j = 1; j < m; j++) {
            int ones = 0;
            for (int i = 0; i < n; i++) {
                ones += (g[i][0]) ? g[i][j] : !g[i][j];//flipped because of the 0th row bit
            }
            res += max(ones, n - ones) * (1 << (m - 1 - j));
        }
        return res;
    }
};