class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& g, int health, int i = 0, int j = 0) {
        //dijkstra with max health sorting
        int n = g.size(), m = g [0].size();
        vector<vector<int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        vector<vector<int>> dp(n, vector<int>(m, 0));//like dis[] array
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pair<int, int>>> pq;//health, position
        dp[0][0] = health - g[0][0];//at each cell lands and health - g[i][j], at last cell health must > 0 for success
        pq.push({ dp[0][0], {0, 0} });
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();
            int x = t.second.first, y = t.second.second, h = t.first;
            if (vis [x][y]) continue;
            vis [x][y] = 1;
            for (auto d : dir) {
                int nx = x + d[0], ny = y + d[1];
                if (min(nx, ny) >= 0 && nx < n && ny < m) {
                    int nh = h - g[nx][ny];
                    if (nh > dp[nx][ny]) {
                        dp[nx][ny] = nh;
                        pq.push({ nh, {nx, ny} });
                    }
                }
            }
        }
        //   dbg(dp);
        return dp [n - 1][m - 1] != 0;
    }
};