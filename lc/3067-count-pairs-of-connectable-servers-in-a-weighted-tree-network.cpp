class Solution {
public:
  void dfs(int i, int dist, vector<int>& pathDist, vector<int>& vis, vector<vector<pair<int, int>>>& g) {
    vis[i] = 1;
    pathDist.push_back(dist);
    for (auto &e : g[i]) {
      if (e.second && !vis[e.first]) {
        dfs(e.first, dist + e.second, pathDist, vis, g);
      }
    }
  }
  vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    int n = edges.size() + 1;
    vector<int> res(n, 0);
    vector<vector<pair<int, int>>> g(n);
    for (auto& e : edges) {
      g[e[0]].push_back({e[1], e[2]});
      g[e[1]].push_back({e[0], e[2]});
    }
    for (int i = 0; i < n; ++i) {
      vector<vector<int>> pathDists;
      for (auto &e : g[i]) {
        if (!e.second) continue;
        vector<int> vis(n, 0);
        vis[i] = 1;
        vector<int> pathDist;
        dfs(e.first, e.second, pathDist, vis, g);
        pathDists.push_back(pathDist);
      }
      for (int j = 0; j < pathDists.size(); ++j) {
        for (int k = j + 1; k < pathDists.size(); ++k) {
          for (int &x : pathDists[j]) {
            for (int &y : pathDists[k]) {
              if (x % signalSpeed == 0 && y % signalSpeed == 0) {
                ++res[i];
              }
            }
          }
        }
      }
    }
    return res;
  }
};
