// Dijkstra's algorithm — single-source shortest paths on a graph with
// non-negative edge weights (use Bellman-Ford instead if weights can be
// negative). Lazy-deletion variant: stale queue entries are just skipped
// when popped rather than removed up front.
//
// Complexity: O((V + E) log V).
//
// Usage:
//   Dijkstra dij(n);
//   dij.addEdge(0, 1, 4);
//   dij.addEdge(0, 2, 1);
//   dij.addEdge(2, 1, 2, false);   // pass false for a directed edge
//   vi dist = dij.shortestPath(0);
struct Dijkstra {
  i64 n;
  vector<vpi> adj; // adj[u] = list of (neighbor, weight)

  Dijkstra(i64 n) {
    this->n = n;
    adj.assign(n, {});
  }

  void addEdge(i64 u, i64 v, i64 w, bool undirected = true) {
    adj[u].pb({ v, w });
    if (undirected)
      adj[v].pb({ u, w });
  }

  vi shortestPath(i64 src) {
    vi dist(n, INF);
    pqg<pi> pq; // min-heap of (dist, vertex), template's greater-ordered priority_queue alias

    dist[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
      auto [d, v] = pq.top();
      pq.pop();

      if (d != dist[v]) continue; // stale entry, a shorter path was already found

      for (auto [to, w] : adj[v]) { // structured bindings don't fit trav()'s single-var shape, kept as a plain range-for
        if (dist[to] > d + w) {
          dist[to] = d + w;
          pq.push({ dist[to], to });
        }
      }
    }

    return dist;
  }
};
