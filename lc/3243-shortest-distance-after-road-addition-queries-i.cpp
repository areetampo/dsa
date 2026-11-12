typedef pair<int, int> pi;
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& Q) {
        vector<int> res;
        vector<vector<int>> G(n, vector<int>());
        for (int i = 0; i < n - 1; i++) G[i].push_back(i + 1);
        for (auto q : Q) {//dijkstra per query
            int u = q[0], v = q[1];
            //v in u's vector means directed edge from u to v with dist 1
            if (find(G[u].begin(), G[u].end(), v) == G[u].end()) G[u].push_back(v);
            priority_queue<pi, vector<pi>, greater<pi>> pq;//{dist, node} min heap
            pq.push({0, 0});
            vector<int> vis(n, 0);
            while (!pq.empty()) {
                int dist = pq.top().first, node = pq.top().second; pq.pop();
                if (node == n - 1) {res.push_back(dist); break;}
                vis[node] = 1;
                for (int &neigh : G[node]) {
                    if (vis[neigh] == 0) pq.push({dist + 1, neigh});
                }
            }
        }
        return res;
    }
};