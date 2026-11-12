// 0-1 BFS — shortest paths on a graph where every edge weight is exactly 0
// or 1, using a deque instead of a priority queue: 0-weight edges push to
// the front (processed next, no cost), 1-weight edges push to the back.
// Achieves the same result as Dijkstra but in O(V + E) instead of
// O((V + E) log V).
//
// Complexity: O(V + E).
//
// Usage:
//   ZeroOneBFS z(n);
//   z.addEdge(0, 1, 0);   // 0-weight edge
//   z.addEdge(1, 2, 1);   // 1-weight edge
//   vi dist = z.shortestPath(0);
//
// NOTE: only valid for 0/1 weights — addEdge doesn't validate this, so
// passing any other weight will silently give wrong answers.
struct ZeroOneBFS {
  i64 n;
  vector<vpi> adj; // adj[u] = list of (neighbor, weight), weight always 0 or 1

  ZeroOneBFS(i64 n) {
    this->n = n;
    adj.assign(n, {});
  }

  void addEdge(i64 u, i64 v, i64 w, bool undirected = true) {
    // w must be 0 or 1
    adj[u].pb({ v, w });
    if (undirected)
      adj[v].pb({ u, w });
  }

  vi shortestPath(i64 src) {
    deque<i64> dq;
    vi dist(n, INF);

    dist[src] = 0;
    dq.push_front(src);

    while (!dq.empty()) {
      i64 v = dq.front();
      dq.pop_front();

      for (auto [to, w] : adj[v]) { // structured bindings don't fit trav()'s single-var shape, kept as a plain range-for
        if (dist[to] > dist[v] + w) {
          dist[to] = dist[v] + w;

          if (w == 0)
            dq.push_front(to);
          else
            dq.push_back(to);
        }
      }
    }

    return dist;
  }
};
