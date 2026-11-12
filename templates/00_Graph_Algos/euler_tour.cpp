// Euler Tour (flattening) — assigns each vertex an entry time tin[v] and
// exit time tout[v] during a single DFS, such that v's entire subtree
// occupies the contiguous range [tin[v], tout[v]] in tin-order. Turns
// subtree queries/updates into range queries/updates on a Fenwick or
// segment tree indexed by tin[].
//
// Complexity: O(V + E) to build.
//
// Usage:
//   EulerTour et(n);
//   et.addEdge(0, 1);
//   et.addEdge(0, 2);
//   ...
//   et.dfs(0);                        // run once from the root
//   bool inSubtree = et.tin[u] <= et.tin[v] && et.tin[v] <= et.tout[u];
//   // u is an ancestor of v (or u == v) iff the above holds
//
// Typical pairing: build a Fenwick tree of size n over tin-order, then a
// "subtree sum" query is just fenwick.query(tin[v], tout[v]), and a
// "add to entire subtree" update is fenwick.add(tin[v], val) combined with
// fenwick.add(tout[v] + 1, -val) if doing difference-array style updates.
//
// NOTE: dfs() is recursive — same stack-depth caveat as the other DFS-based
// structures here: very deep/skewed trees can risk stack overflow.
struct EulerTour {
  i64 timer = 0;

  vi tin, tout;
  vvi adj;

  EulerTour(i64 n) {
    adj.assign(n, {});
    tin.resize(n);
    tout.resize(n);
  }

  void addEdge(i64 u, i64 v) {
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void dfs(i64 v, i64 p = -1) {
    tin[v] = timer++;

    trav(to, adj[v])
      if (to != p)
        dfs(to, v);

    tout[v] = timer - 1;
  }
};
