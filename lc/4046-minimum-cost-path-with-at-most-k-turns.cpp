class Solution {
public:
    int minCost(vector<vector<int>>& g, int k) {
        // n, m <= 75 grid <= 1e3, k <= min(n, m)
        int n = g.size(), m = g[0].size();
        // cost, turns, to determine turn, i, j
        // 3rd param:
        // 0 if vertical: (i, j) -> (i +/- 1, j)
        // 1 if horizontal: (i, j) -> (i, j +/- 1)
        // initially -1: not moved from any direction
        priority_queue<
            tuple<int, int, int, int, int>,
            vector<tuple<int, int, int, int, int>>,
            greater<tuple<int, int, int, int, int>>
        > pq;
        // i, j, turns, direction
        vector<vector<vector<vector<int>>>> cost(n, vector<vector<vector<int>>>(m, 
            vector<vector<int>>(k + 1, vector<int>(3, INT_MAX)))); 
            // 3: last move was i(0) or j(1) change or 2 for initial state (arriving at 0,0)

        cost[0][0][0][2] = g[0][0];
        pq.push({g[0][0], 0, 2, 0, 0});

        while (!pq.empty()) {
            auto [c, t, d, i, j] = pq.top();
            pq.pop();

            if (c != cost[i][j][t][d]) continue; // skip stale dijkstra states

            if (i == n - 1 && j == m - 1) return c;

            for (int x = 0, dir[5] = {1,0,-1,0,1}; x < 4; x++) {
                int ni = i + dir[x], nj = j + dir[x + 1];
                if (min(ni, nj) < 0 || ni == n || nj == m) continue;

                int nc = c + g[ni][nj], 
                    nt = t + (d == 2 ? 0 : // journey starts: no change in turns
                            d == 0 ? i == ni : // prev vertical: +0 if next vertical
                                    j == nj), // prev horizontal: +0 if next horizontal
                    nd = j != nj; // i change (vertical) = 0, j change (horizontal) = 1

                if (nt > k || cost[ni][nj][nt][nd] <= nc) continue;
                cost[ni][nj][nt][nd] = nc;

                pq.push({nc, nt, nd, ni, nj});
            }

        }

        return -1;
    }
};