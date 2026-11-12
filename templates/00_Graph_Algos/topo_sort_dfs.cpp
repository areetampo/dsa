// Topological sort via DFS: run DFS from every unvisited vertex, appending
// each vertex to the result AFTER exploring all its neighbors (postorder),
// then reverse the whole list at the end.
//
// Complexity: O(V + E).
//
// Usage:
//   vvi adj(n);
//   adj[0].pb(1); adj[1].pb(2); // edges u -> v
//   vi order = topoSortDFS(adj);
//
// NOTE: named topoSortDFS (not just topoSort) so it can coexist with
// topo_sort_bfs_khan.cpp's topoSortKahn if both are ever pasted in at once.
// Also, topoDFS is recursive — same stack-depth caveat as the other
// DFS-based structures here.
void topoDFS(i64 v, vvi& adj, vi& vis, vi& topo) {
  vis[v] = 1;
  trav(to, adj[v])
    if (!vis[to])
      topoDFS(to, adj, vis, topo);
  topo.pb(v);
}

vi topoSortDFS(vvi& adj) {
  i64 n = sz(adj);
  vi vis(n);
  vi topo;

  fo(i, 0, n)
    if (!vis[i])
      topoDFS(i, adj, vis, topo);

  reverse(all(topo));
  return topo;
}
