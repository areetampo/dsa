// Topological sort via Kahn's algorithm (BFS): repeatedly remove vertices
// with in-degree 0. If the result has fewer than n vertices, the graph has
// a cycle (no valid topological order exists) — check for that if needed.
//
// Complexity: O(V + E).
//
// Usage:
//   vvi adj(n);
//   adj[0].pb(1); adj[1].pb(2); // edges u -> v
//   vi order = topoSortKahn(adj);
//   if (sz(order) < n) { /* graph has a cycle */ }
//
// NOTE: named topoSortKahn (not just topoSort) specifically so it can
// coexist with topo_sort_dfs.cpp's topoSortDFS if you ever want both pasted
// in at once — otherwise pasting both would double-define topoSort.
vi topoSortKahn(vvi& adj) {
  i64 n = sz(adj);
  vi indeg(n);

  fo(i, 0, n)
    trav(j, adj[i])
    indeg[j]++;

  queue<i64> q;
  fo(i, 0, n)
    if (!indeg[i])
      q.push(i);

  vi topo;
  while (!q.empty()) {
    i64 v = q.front();
    q.pop();
    topo.pb(v);

    trav(to, adj[v]) {
      indeg[to]--;
      if (!indeg[to])
        q.push(to);
    }
  }

  return topo;
}
