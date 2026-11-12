class Solution {
public:
    int firstCompleteIndex(vector<int>& v, vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        unordered_map<int, pair<int, int>> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[g[i][j]] = {i, j};
            }
        }
        vector<int> r(n, m), c(m, n);
        for (int i = 0; i < v.size(); i++) {
            auto [row, col] = map[v[i]];
            // cout << v[i] << ", " << row << " " << col << ", " << r[row] << " " << c[col] << "\n";
            if (--r[row] == 0 || --c[col] == 0) return i;
        } 
        return -1;
    }
};