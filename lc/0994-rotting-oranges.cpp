class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        //0 -> empty
        //1 -> fresh
        //2 -> rotten
        int n = g.size(), m = g[0].size(), total = 0, rotten = 0, time = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) {
                total += g[i][j] > 0;
                if (g[i][j] == 2) rotten++, vis[i][j] = 1, q.push({i, j});
            }
        if (rotten == 0 && total > 0) return -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                // cout << x << " " << y << "\n";
                for (int i = 0; i < 4; i++) {
                    int new_x = x + dx[i], new_y = y + dy[i];
                    if (min(new_x, new_y) >= 0 && new_x < n && new_y < m && 
                        g[new_x][new_y] == 1 && !vis[new_x][new_y]) {
                        vis[new_x][new_y] = 1;
                        rotten++;
                        q.push({new_x, new_y});
                    }
                }
            }
            time += !q.empty();
            // cout << time << "-------\n";
        }
        return rotten == total ? time : -1;
    }
};