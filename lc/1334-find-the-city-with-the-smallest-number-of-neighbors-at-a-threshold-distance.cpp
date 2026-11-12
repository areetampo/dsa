class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& e, int k) {
    vector<vector<int>> v(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i) v[i][i] = 0;
    for (auto E : e) {
      v[E[0]][E[1]] = E[2];
      v[E[1]][E[0]] = E[2];
    }
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        if (i != k)
        for (int j = 0; j < n; ++j) {
          if (i == j || k == j) continue;
          if (v[i][k] != INT_MAX && v[k][j] != INT_MAX && v[i][j] > v[i][k] + v[k][j]) {
            v[i][j] = v[i][k] + v[k][j];
          }
        }
      }
    }
    int minReachableCities = INT_MAX;
    int res = -1;
    for (int i = 0; i < n; ++i) {
      int reachableCities = 0;
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (v[i][j] <= k) ++reachableCities;
      }
      if (reachableCities < minReachableCities) res = i;
      else if (reachableCities == minReachableCities) res = max(res, i);
      minReachableCities = min(minReachableCities, reachableCities);
    }
    return res;
  }
};