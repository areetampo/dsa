// Kosaraju's algorithm — finds strongly connected components (SCCs) of a
// directed graph via two DFS passes: first computes a finishing-time order
// on the original graph, then DFS's the reversed graph in reverse finishing
// order — each DFS tree from that second pass is exactly one SCC.
//
// Complexity: O(V + E).
//
// Usage:
//   SCC scc(n);
//   scc.addEdge(0, 1);
//   scc.addEdge(1, 2);
//   ...
//   vvi comps = scc.build();   // comps[i] = list of vertices in the i-th SCC
//
// NOTE: dfs1/dfs2 are recursive — same stack-depth caveat as the other
// DFS-based structures here.
struct SCC {
  i64 n;

  vvi g, rg; // g = original graph, rg = reversed graph
  vi vis;
  vi order; // finishing-time order from the first DFS pass
  vi comp;  // scratch buffer for the current component during dfs2

  SCC(i64 n) {
    this->n = n;
    g.assign(n, {});
    rg.assign(n, {});
  }

  void addEdge(i64 u, i64 v) {
    g[u].pb(v);
    rg[v].pb(u);
  }

  void dfs1(i64 v) {
    vis[v] = 1;
    trav(to, g[v])
      if (!vis[to])
        dfs1(to);
    order.pb(v);
  }

  void dfs2(i64 v) {
    vis[v] = 1;
    comp.pb(v);
    trav(to, rg[v])
      if (!vis[to])
        dfs2(to);
  }

  vvi build() {
    vis.assign(n, 0);
    fo(i, 0, n)
      if (!vis[i])
        dfs1(i);

    reverse(all(order));

    vis.assign(n, 0);
    vvi scc;

    trav(v, order) {
      if (vis[v]) continue;
      comp.clear();
      dfs2(v);
      scc.pb(comp);
    }

    return scc;
  }
};
