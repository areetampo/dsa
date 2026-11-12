typedef tuple<int, int, int> ti;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& g) {
        //now contrary to 2577, here a non dijkstra apprach can be used
        //called 0-1 BFS
        //time: nmlog(mn) -> nm
        //in 2577 and other grid or graph q with non 0/1 edge weights (in graphs)
        //and call values (in grid) require the dijkstra approach since each time 
        //a new node/cell is reached a and relaxed neighbours need to get added to
        //pq (not q) since the min each time must come at top
        //but here either there's a obstacle (curr + 1) or no obstacle 
        //(curr + 0 -> total num of obstacles removed stays the same)
        //so lets say a pq is used:
        //since the previously removed object that was at the front cuz
        //that was the min_obstacles_removed till now to reach that cell but now 
        //reaching a new cell with same num of obstacles removed that would
        //automatically appear at top of a pq when added (cuz same number of obs
        //removed which is the sorting parameter) 
        //now if there is a obstacle, then it increased the count of curr obstacles
        //by 1 and cannot be added to front of pq (lets say an equal number of 
        //obstacles removed is alr present at front of pq so putting a +1 obs there
        //doesnt make sense and must not be poped next time)
        //since its just +1 and will be >= previously added values in pq, put it at
        //the end, this is the beauty of 0/1 -> put at front/end -> so use a DEQUE
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        int n = g.size(), m = g[0].size();
        //max 1e5 cells in grid and g[0][0] = 0 so max obstacles removed = 1e5 - 1
        vector<vector<int>> d(n, vector<int>(m, 1e5 - 1));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        deque<ti> dq;//first parameter is the obstacles removed
        dq.push_front({0, 0, 0});
        while (!dq.empty()) {
            auto [obs_removed, x, y] = dq.front(); dq.pop_front();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == n - 1 && y == m - 1) return obs_removed;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];
                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int obs_removed_to_reach_new_cell = obs_removed + g[newX][newY];
                    if (d[newX][newY] > obs_removed_to_reach_new_cell) {
                        d[newX][newY] = obs_removed_to_reach_new_cell;
                        ti t = {d[newX][newY], newX, newY};
                        if (g[newX][newY]) dq.push_back(t); 
                        else dq.push_front(t);
                    }
                }
            }
        }
        return -1;
    }
};
//dijkstra approach
// int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
// int n = g.size(), m = g[0].size();
// //max 1e5 cells in grid and g[0][0] = 0 so max obstacles removed = 1e5 - 1
// vector<vector<int>> d(n, vector<int>(m, 1e5 - 1));
// vector<vector<bool>> vis(n, vector<bool>(m, 0));
// priority_queue<ti, vector<ti>, greater<ti>> pq;//min heap on obstacles removed
// pq.push({0, 0, 0});
// while (!pq.empty()) {
//     auto [obs_removed, x, y] = pq.top(); pq.pop();
//     if (vis[x][y]) continue;
//     vis[x][y] = 1;
//     if (x == n - 1 && y == m - 1) return obs_removed;
//     for (int i = 0; i < 4; i++) {
//         int newX = x + dx[i], newY = y + dy[i];
//         if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
//             int obs_removed_to_reach_new_cell = obs_removed + g[newX][newY];
//             if (d[newX][newY] > obs_removed_to_reach_new_cell) {
//                 d[newX][newY] = obs_removed_to_reach_new_cell;
//                 pq.push({d[newX][newY], newX, newY});
//             }
//         }
//     }
// }
// return -1;