
/********************************************************/
/* Binary Lifting              */
/********************************************************/
/*
    PURPOSE:
      Preprocess a rooted tree to answer queries involving ancestors
      and paths between vertices efficiently.

      The Lowest Common Ancestor (LCA) of u and v is the deepest
      vertex that is an ancestor of both u and v.

      Binary lifting lets us move upward by powers of two instead
      of climbing one edge at a time.

    PREPROCESSING:
      build(root) roots the tree and computes:
        - depth[v]: distance from root to v, measured in edges.
        - up[i][v]: the 2^i-th ancestor of v.

      In particular:
        up[0][v] = parent of v
        up[1][v] = 2nd ancestor of v
        up[2][v] = 4th ancestor of v
        up[3][v] = 8th ancestor of v
        ...

      The binary-lifting table is built using:
        up[i][v] = up[i - 1][up[i - 1][v]]

      This works because moving 2^i edges upward is equivalent
      to making two consecutive jumps of 2^(i-1) edges.

    QUERIES:
      lca(u, v):
        Returns the lowest common ancestor of u and v.

      kthAncestor(v, k):
        Returns the ancestor k edges above v.

      dist(u, v):
        Returns the number of edges on the unique path from u to v.
        If w = lca(u, v), the path goes from u up to w, then down
        from w to v:
          dist(u, v) = depth[u] + depth[v] - 2 * depth[w]

    COMPLEXITY:
      Let LOG = ceil(log2(n)) + 1, sufficient to represent all
      ancestor jumps needed for a tree of n vertices.

      Preprocessing:
        Time:  O(n log n)
        Space: O(n log n) for the lifting table,
               plus O(n) for adjacency lists and depths.

      Each query:
        lca(u, v):         O(log n)
        kthAncestor(v, k): O(log n)
        dist(u, v):        O(log n)

    USAGE:
      Vertices are indexed from 0 to n - 1.

      LCA lca(n);
      lca.addEdge(0, 1);
      lca.addEdge(0, 2);
      lca.addEdge(1, 3);
      lca.addEdge(1, 4);

      lca.build();               // Root the tree at vertex 0.
      lca.lca(3, 4);              // Returns 1.
      lca.dist(3, 4);             // Returns 2.
      lca.kthAncestor(3, 1);      // Returns 1.
      lca.kthAncestor(3, 2);      // Returns 0.

    ASSUMPTIONS AND NOTES:
      - The input must be a connected, undirected tree.
      - addEdge(u, v) must be called before build().
      - build(root) must be called before any query.
      - The root is its own ancestor at every lifting level.
        Therefore, a jump above the root stays at the root.
      - kthAncestor(v, k) returns the root if k goes beyond
        the number of edges between v and the root.
      - DFS is recursive. A highly skewed tree can cause stack
        overflow; use iterative preprocessing if necessary.
      - Query vertices and edges must be valid.
*/
/********************************************************/
struct LCA {
  i64 n, LOG;

  // up[i][v] = ancestor of v exactly 2^i edges above it.
  // up[0] stores parents; higher levels combine smaller jumps.
  vvi up, adj;

  // Number of edges from the chosen root to each vertex.
  vi depth;

  LCA(i64 n) {
    this->n = n;

    // Find enough lifting levels to handle jumps up to the tree's
    // height. The extra level also handles powers-of-two boundaries.
    LOG = 1;
    while ((1LL << LOG) <= n) LOG++;

    adj.assign(n, {});
    up.assign(LOG, vi(n));
    depth.assign(n, 0);
  }

  // Add an undirected edge. Call this for every tree edge before build().
  void addEdge(i64 u, i64 v) {
    adj[u].pb(v);
    adj[v].pb(u);
  }

  void dfs(i64 v, i64 p) {
    // The root is passed as its own parent, so every ancestor jump
    // above the root remains at the root instead of going out of bounds.
    up[0][v] = p;

    // Build this vertex's entire lifting table from its parent's table.
    // To move 2^i edges up, first move 2^(i-1) edges, then another
    // 2^(i-1) edges from the vertex reached by the first jump.
    fo(i, 1, LOG)
      up[i][v] = up[i - 1][up[i - 1][v]];

    // Visit the children and assign their depths.
    // Since the graph is a tree, skipping the parent is sufficient
    // to avoid walking back along the edge we just traversed.
    trav(to, adj[v]) {
      if (to == p) continue;
      depth[to] = depth[v] + 1;
      dfs(to, v);
    }
  }

  // Root the tree and preprocess depths and binary-lifting ancestors.
  // Must be called after all edges have been added.
  void build(i64 root = 0) {
    dfs(root, root);
  }

  // Return the ancestor of v exactly k edges above it.
  // Process the set bits of k: a set bit i means we must jump 2^i
  // edges upward. Combining these jumps moves v by exactly k edges.
  i64 kthAncestor(i64 v, i64 k) {
    fo(i, 0, LOG)
      if (k & (1LL << i))
        v = up[i][v];

    return v;
  }

  // Return the deepest vertex that is an ancestor of both a and b.
  i64 lca(i64 a, i64 b) {
    // First equalize depths. If one vertex is deeper, lift it until
    // both vertices are the same distance from the root.
    if (depth[a] < depth[b]) swap(a, b);

    a = kthAncestor(a, depth[a] - depth[b]);

    // If they meet after equalizing depths, that vertex is the LCA.
    if (a == b) return a;

    // Both vertices now have equal depth but are not equal.
    // Try the largest jumps first. Whenever their 2^i-th ancestors
    // differ, move both vertices up by 2^i edges.
    //
    // Because their ancestors at that level differ, this jump cannot
    // move either vertex to the LCA or above it. We remain below the
    // LCA and progressively get closer to it.
    //
    // After processing every level, a and b are distinct children
    // of the LCA, so their immediate parents are the same vertex.
    fr(i, LOG - 1, 0) {
      if (up[i][a] != up[i][b]) {
        a = up[i][a];
        b = up[i][b];
      }
    }

    // The vertices are now immediately below their LCA.
    return up[0][a];
  }

  // Number of edges on the unique path from u to v.
  // The path goes up from u to w = lca(u, v), then down to v.
  // depth[u] + depth[v] counts both root paths, so subtract twice
  // the root-to-w distance to remove their shared portion.
  i64 dist(i64 u, i64 v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
  }
};
