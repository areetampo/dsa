class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mt) {
        int n = mt.size(), m = mt[0].size();
        vector<array<int, 2>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        priority_queue<tuple<int, pair<int, int>, int>, vector<tuple<int, pair<int, int>, int>>, greater<tuple<int, pair<int, int>, int>>> pq;//min heap arrival time, cell, add 1 in next move or not (not means add 2)
        vector<vector<int>> vis(n, vector<int>(m , 0));
        vis[0][0] = 1;
        pq.push({0, {0, 0}, 1});
        while (!pq.empty()) {
            auto [arrival_time, p, add_one] = pq.top(); pq.pop();
            int x = p.first, y = p.second;
            if (x == n - 1 && y == m - 1) return arrival_time;
            for (auto d : dir) {
                int newX = x + d[0], newY = y + d[1];
                if (0 <= newX && newX < n && 0 <= newY && newY < m && !vis[newX][newY]) {
                    vis[newX][newY] = 1;
                    int req_time = mt[newX][newY];
                    pq.push({(add_one ? 1 : 2) + max(req_time, arrival_time), {newX, newY}, !add_one});
                }
            }
        }
        return -1;//ans always exists
    }
};