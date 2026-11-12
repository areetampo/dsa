class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<long long>> g(n, vector<long long>(n, 0ll));//time >= 1
        for (auto& i : roads) {
            g[i[0]][i[1]] = i[2];
            g[i[1]][i[0]] = i[2];
        }
        vector<pair<long long, int>> dist(n, {LLONG_MAX, 0});
        vector<bool> vis(n, 0);
        dist[0] = {0ll, 1};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0ll, 0});
        while (!pq.empty()) {
            auto [d, t] = pq.top(); pq.pop();
            if (vis[t] == 1) continue;
            vis[t] = 1;
            // cout << t << " " << dist[t].first << " " << dist[t].second << "---\n";
            for (int ng = 0; ng < n; ng++) {
                if (g[t][ng] == 0 || vis[ng] == 1) continue;
                if (dist[ng].first > dist[t].first + g[t][ng]) {
                    dist[ng] = {dist[t].first + g[t][ng], dist[t].second};
                    pq.push({dist[ng].first, ng});
                } else if (dist[ng].first == dist[t].first + g[t][ng]) {
                    dist[ng].second = (dist[ng].second + dist[t].second) % mod;
                }
                // cout << ng << " " << dist[ng].first << " " << dist[ng].second << "\n";
            }
            cout << "---\n";
        }
        return dist[n - 1].second;
    }
};