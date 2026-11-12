typedef tuple<int, int, int> ti;
class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {//dijkstra
        //g[0][0] = 0 and (n - 1, m - 1) always reachable since we can always 
        //go back and forth between 2 cells to keep increasing time 
        //its not reachable only when we cant make the first move (move from (0, 0))
        //so case for it:
        if (min(g[0][1], g[1][0]) > 1) return -1;
        int dx[] = {0, 0, 1, -1}, dy[] = {-1, 1, 0, 0};
        int n = g.size(), m = g[0].size();
        vector<vector<int>> d(n, vector<int>(m, 1e5 + 3));//dist arr, max val in g[][] is 1e5 so imagine n-1, m-1 is 1e5 and reached n-2,m-1 or n-1,m-2 at 1e5-1 so would need +3 to land at n-1,m-1
        d[0][0] = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<ti, vector<ti>, greater<ti>> pq;//min heap on arrival time
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [time, x, y] = pq.top(); pq.pop();
            if (vis[x][y]) continue;//reached cell previously in less time and all +ve values so not possible reach ever in lesser time (dijkstra)
            vis[x][y] = 1;
            if (x == n - 1 && y == m - 1) return time;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];
                //now to calc reaching time to new cell, +1 for travelling from curr cell but if (g[newX][newY] - time > 1) then need to go back and forth b/w a prev cell and curr cell (each taking +2 time) so 1 extra will take 2 extra time, 2 will take 2, 3 will take 4, 4 will take 4, 5 will take 6...(remaining + 1) / 2 * 2...so overall
                //currTime + 1 + max(0, ((remaining + 1) / 2) * 2) -> 
                //note that 2nd arg will be <= 0 if remaining < 1
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int remaining = g[newX][newY] - (time + 1);
                    int newTime = time + 1 + max(0, ((remaining + 1) / 2) * 2);
                    if (d[newX][newY] > newTime) {
                        d[newX][newY] = newTime;
                        pq.push({newTime , newX, newY});
                    }

                }
            }
        }
        return -2;
    }
};