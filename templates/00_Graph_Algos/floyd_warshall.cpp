// Floyd-Warshall — all-pairs shortest paths on a graph given as an n x n
// distance matrix (dist[i][j] = weight of edge i->j, or INF if none;
// dist[i][i] should be 0). Works with negative edge weights, but not
// negative cycles (those would keep pulling dist[i][i] below 0 — check for
// that if your graph might have one).
//
// Complexity: O(n^3).
//
// Usage:
//   vvi dist(n, vi(n, INF));
//   fo(i, 0, n) dist[i][i] = 0;
//   dist[0][1] = 4; dist[1][2] = 3; // fill in known edges
//   dist = floydWarshall(dist);     // dist[i][j] is now the shortest i->j
vvi floydWarshall(vvi dist) {
  i64 n = sz(dist);

  fo(k, 0, n)
    fo(i, 0, n)
    fo(j, 0, n)
    if (dist[i][k] != INF && dist[k][j] != INF)
      smin(dist[i][j], dist[i][k] + dist[k][j]);

  return dist;
}
