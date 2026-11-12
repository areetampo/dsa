// Tarjan's algorithm for articulation points (cut vertices) in an undirected
// graph — a vertex whose removal increases the number of connected
// components. Uses DFS discovery times (tin) and low-link values (low): a
// non-root vertex v is a cut vertex if some child `to` has low[to] >= tin[v]
// (i.e. that subtree can't reach back above v without going through v); the
// root is a cut vertex iff it has more than one DFS-tree child.
//
// Complexity: O(V + E).
//
// Usage:
//   Articulation art(n);
//   art.addEdge(0, 1);
//   art.addEdge(1, 2);
//   ...
//   art.dfs(0);           // run from any start vertex per connected component
//   dbg(art.points);      // list of articulation points found
//
// NOTE: `points` can contain duplicates if a vertex qualifies via more than
// one child — dedupe with sort(all(points)) + erase(unique(...)) if you need
// a clean set. Also, dfs() is recursive, so on very deep/skewed graphs
// (long paths) it can risk stack overflow — convert to an explicit stack if
// that's a concern for your input size.
struct Articulation {
  i64 timer = 0;

  vvi adj;
  vi tin, low, vis;
  vi points;

  Articulation(i64 n) {
    adj.assign(n, {});
    tin.resize(n);
    low.resize(n);
    vis.assign(n, 0);
  }

  void addEdge(i64 u, i64 v) {
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void dfs(i64 v, i64 p = -1) {
    vis[v] = 1;
    tin[v] = low[v] = timer++;

    i64 child = 0;

    trav(to, adj[v]) {
      if (to == p) continue;

      if (vis[to]) {
        smin(low[v], tin[to]); // back edge: update low-link directly
      } else {
        dfs(to, v);
        smin(low[v], low[to]);

        // to's subtree can't reach above v, so v is a cut vertex
        // (unless v is the root, handled separately below)
        if (low[to] >= tin[v] && p != -1)
          points.pb(v);

        child++;
      }
    }

    // root special case: it's a cut vertex iff it has more than one DFS child
    if (p == -1 && child > 1)
      points.pb(v);
  }
};
