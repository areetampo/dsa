class Solution {
public://BFS
  bool isBipartite(vector<vector<int>>& g) {
    int n = g.size();
    vector<int> vis(n, 0);
    vector<int> color(n, 0);//0 means no color
    queue<int> q;
    for (int i = 0; i < n; ++i) {//for disjoint graph
      if (!vis[i]) {
        vis[i] = 1;
        q.push(i);
        color[i] = -1;//start node
        while (!q.empty()) {//bfs for disjoint segment
          int top = q.front(); q.pop();
          int clr = color[top];
          for (int nbr : g[top]) {
            if (color[nbr] == clr) return 0;
            color[nbr] = -clr;
            if (!vis[nbr]) {
              vis[nbr] = 1; q.push(nbr);
            }
          }
        }
      }
    }
    return 1;
  }
};
//DFS 
//check is a dfs func
// bool check(int i, int iColor, vector<int>& vis, vector<int>& color, vector<vector<int>>& g) {
//   vis[i] = 1;
//   for (int nbr : g[i]) {
//     if (color[nbr] == iColor) return 0;
//     color[nbr] = iColor == 1 ? -1 : 1;
//     if (!vis[nbr] && !check(nbr, color[nbr], vis, color, g)) return 0;
//   }
//   return 1;
// }
// bool isBipartite(vector<vector<int>>& g) {
//   int n = g.size();
//   vector<int> color(n, 0);//0 means no color
//   vector<int> vis(n, 0);
//   for (int i = 0; i < n; ++i) {//for disjoint graph
//     if (!vis[i]) {
//       color[i] = -1;//start node for coloring
//       if (!check(i, -1, vis, color, g)) return 0;
//     }
//   }
//   return 1;
// }