class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size(), dx[] = {0, 0, 1, -1},
            dy[] = {1, -1, 0, 0};
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1)
                    g[i][j] = 0, q.push({0, i, j});
                else
                    g[i][j] = -1;
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int h = get<0>(t), i = get<1>(t), j = get<2>(t);
            for (int k = 0; k < 4; k++) {
                int _i = i + dx[k], _j = j + dy[k];
                if (min(_i, _j) >= 0 && _i < n && _j < m && g[_i][_j] == -1) {
                    g[_i][_j] = h + 1;
                    q.push({h + 1, _i, _j});
                }
            }
            // dbg(g);
        }
        return g;
    }
};