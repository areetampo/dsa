class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& p, int src, int des) {
        vector<vector<pair<int, double>>> adj(n);//prevent mle by not traversing all n edges
        for (int i = 0; i < e.size(); i++) {
            auto E = e[i];
            adj[E[0]].push_back({E[1], p[i]});
            adj[E[1]].push_back({E[0], p[i]});
        }
        vector<int> vis(n, 0);
        priority_queue<pair<double, int>> pq;//max heap
        pq.push({1, src});//starting prob 1 so multiply by 1 
        while (!pq.empty()) {
            auto x = pq.top(); pq.pop(); 
            int node = x.second; double prob = x.first;
            if (node == des) return prob;
            if (!vis[node]) {
                vis[node] = 1;
                for (auto k : adj[node]) {
                    double y = k.second; int neigh = k.first;
                    pq.push({prob * y, neigh});
                }
            }
        }
        return 0;
    }
};