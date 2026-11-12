// Disjoint Set Union (Union-Find) with path compression + union by size.
//
// Classic building block for Kruskal's MST, connectivity/component-counting
// queries, cycle detection in undirected graphs, offline "are these two
// connected" queries, etc.
//
// In addition to the basic DSU operations, this version provides helpers for
// getting component sizes, counting components, finding all roots, and
// collecting all nodes belonging to each component.
//
// Complexity:
//   find/unite/same/size = O(alpha(n)) amortized (effectively constant)
//   components           = O(1)
//   roots                = O(n)
//   groups               = O(n * alpha(n)) amortized (effectively O(n))
//
// Usage:
//   DSU dsu(n);              // n elements, initially each its own set (0..n-1)
//
//   dsu.unite(0, 1);
//   dsu.unite(1, 2);
//
//   dsu.same(0, 2);           // true
//   dsu.find(2);              // representative/root of 2's set
//   dsu.size(1);              // 3
//   dsu.components();         // number of connected components
//
//   vi r = dsu.roots();       // all current component roots
//   auto g = dsu.groups();    // root -> all nodes in that component
//
// NOTE:
//   sz[x] is meaningful only when x is a root. To get the size of the
//   component containing x, always use size(x), which internally does
//   sz[find(x)].
//
// NOTE:
//   The member `sz` shadows the template's global sz() function inside this
//   struct's own methods. Harmless here since DSU never needs container sizes
//   internally, but if you ever do, qualify it as ::sz(...) from within a
//   DSU method.

struct DSU {
  vi par, sz;
  i64 comps; // current number of connected components

  // Initially every element is its own component.
  DSU(i64 n) : par(n), sz(n, 1), comps(n) {
    iota(all(par), 0);
  }

  // Find the ultimate parent/root of x.
  //
  // Path compression makes every node visited on the way point directly
  // to the root, making future find() operations very fast.
  i64 find(i64 x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }

  // Merge the sets containing a and b.
  //
  // Returns false if they were already in the same set (no merge happened),
  // otherwise returns true.
  //
  // Union by size always attaches the smaller component below the larger
  // component's root, keeping the trees shallow.
  bool unite(i64 a, i64 b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;

    if (sz[a] < sz[b]) swap(a, b);

    par[b] = a;
    sz[a] += sz[b];
    comps--;

    return true;
  }

  // True iff a and b are currently in the same component.
  bool same(i64 a, i64 b) {
    return find(a) == find(b);
  }

  // Size of the component containing x.
  //
  // We use sz[find(x)] because sz[x] is only valid when x itself is a root.
  i64 size(i64 x) {
    return sz[find(x)];
  }

  // Number of connected components currently present.
  //
  // Maintained during unite(), so this is O(1).
  i64 components() {
    return comps;
  }

  // Return all current component roots.
  //
  // Every connected component has exactly one root.
  vi roots() {
    vi res;

    fo(i, 0, sz(par)) {
      if (find(i) == i)
        res.pb(i);
    }

    return res;
  }

  // Return all components as:
  //
  //   root -> [all nodes belonging to that component]
  //
  // Example:
  //   0 -> [0, 1, 2]
  //   3 -> [3]
  //   4 -> [4, 5]
  //
  // The root is the ultimate parent returned by find().
  map<i64, vi> groups() {
    map<i64, vi> res;

    fo(i, 0, sz(par))
      res[find(i)].pb(i);

    return res;
  }

  // Return the sizes of all current components.
  //
  // Example:
  //   components = { [0,1,2], [3], [4,5] }
  //   returns { 3, 1, 2 }
  //
  // The order follows the ordering of the roots.
  vi component_sizes() {
    vi res;

    fo(i, 0, sz(par)) {
      if (find(i) == i)
        res.pb(sz[i]);
    }

    return res;
  }

  // Size of the largest connected component.
  i64 max_size() {
    i64 ans = 0;

    fo(i, 0, sz(par)) {
      if (find(i) == i)
        ans = max(ans, sz[i]);
    }

    return ans;
  }
};
