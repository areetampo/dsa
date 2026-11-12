class Solution {
public:
void util(int start, unordered_map<int, unordered_map<int, int>>& g, vector<int>& res, vector<int>& vis, vector<int>& d) {
    int n = g.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//time to reach, node
    pq.push({ 0, start });
    while (!pq.empty()) {
        int t = pq.top().first, node = pq.top().second; pq.pop();
        // cout << "time: " << t << " node: " << node << endl;
        if (!vis[node]) {
            vis[node] = 1;
            // cout << node << " vis" << endl;
            if (t >= d[node]) continue;
            res[node] = t;
            for (auto i = g[node].begin(); i != g[node].end(); ++i) {
                int nbr = i->first, w = i->second;
                if (!vis[nbr]) {
                    // cout << "added " << nbr << " with reach time " << t + w << endl;
                    pq.push({ t + w, nbr });
                }
            }
        }
    }
}
vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& d) {
    unordered_map<int, unordered_map<int, int>> g;
    for (auto E : edges) {
        if (E[0] == E[1]) continue;
        int u = E[0], v = E[1], w = E[2];
        if (g.find(u) == g.end() || g[u].find(v) == g[u].end()) {
            g[u][v] = w;
            g[v][u] = w;
        }
        else {
            g[u][v] = min(g[u][v], w);
            g[v][u] = min(g[v][u], w);
        }
    }
    // for (auto i = g.begin(); i != g.end(); ++i) {
    //     cout << i->first << ": ";
    //     for (auto j = g[i->first].begin(); j != g[i->first].end(); ++j)
    //         cout << j->first << " " << j->second << ", ";
    //     cout << endl;
    // }
    vector<int> vis(n, 0);
    vector<int> res(n, -1);
    for (int i : vis) {
        if (!i) {
            util(i, g, res, vis, d);
        }
    }
    // for (int a : res) cout << a << " ";
    return res;
}
};