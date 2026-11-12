// Tarjan's algorithm for bridges — an edge (u, v) whose removal increases
// the number of connected components (unlike articulation points, which are
// vertices). Uses the same tin/low-link DFS as Articulation, but the
// condition is low[to] > tin[v] (strict), not >= — a bridge means to's
// subtree has NO way back to v or higher, not even directly to v itself.
//
// Complexity: O(V + E).
//
// Usage:
//   Bridges br(n);
//   br.addEdge(0, 1);
//   br.addEdge(1, 2);
//   ...
//   br.dfs(0);            // run from any start vertex per connected component
//   dbg(br.bridges);      // list of (u, v) bridge edges found
//
// NOTE: dfs() is recursive — same stack-depth caveat as Articulation: very
// deep/skewed graphs can risk stack overflow, convert to an explicit stack
// if that's a concern for your input size. Also, this doesn't handle
// multi-edges (a direct duplicate edge u-v would look like a back edge and
// suppress a real bridge) — dedupe parallel edges first if your graph has them.
struct Bridges {
  i64 timer = 0;

  vvi adj;
  vi tin, low, vis;
  vpi bridges;

  Bridges(i64 n) {
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

    trav(to, adj[v]) {
      if (to == p) continue;

      if (vis[to]) {
        smin(low[v], tin[to]); // back edge: update low-link directly
      } else {
        dfs(to, v);
        smin(low[v], low[to]);

        // to's subtree has no path back to v or above -> (v, to) is a bridge
        if (low[to] > tin[v])
          bridges.pb({ v, to });
      }
    }
  }
};
