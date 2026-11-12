// Bellman-Ford — single-source shortest paths, handles negative edge
// weights (unlike Dijkstra). Relaxes every edge n-1 times; if nothing
// changes in a full pass, it's converged early.
//
// Complexity: O(V * E).
//
// Usage:
//   vector<Edge> edges = {{0,1,4}, {0,2,1}, {2,1,2}};
//   vi dist = bellmanFord(3, edges, 0);   // shortest dist from vertex 0
//
// NOTE: this does NOT detect negative cycles — a graph with one will just
// keep improving distances forever. To detect one, run a single extra
// relaxation pass after the loop below; if any edge still relaxes, a
// negative cycle is reachable from src.
struct Edge {
  i64 u, v, w;
};

vi bellmanFord(i64 n, vector<Edge>& edges, i64 src) {
  vi dist(n, INF);
  dist[src] = 0;

  fo(i, 0, n - 1) {
    bool changed = false;

    trav(e, edges) {
      if (dist[e.u] == INF) continue;

      if (dist[e.v] > dist[e.u] + e.w) {
        dist[e.v] = dist[e.u] + e.w;
        changed = true;
      }
    }

    if (!changed) break; // converged early, no need to run all n-1 passes
  }

  return dist;
}
