// Lazy-propagation Segment Tree — range add updates, range sum queries.
// 0-indexed: build/update/query all take inclusive [l, r] in 0..n-1.
//
// Complexity: build is O(n); update/query are both O(log n) per call.
//
// Usage:
//   vi a = {1, 2, 3, 4, 5};      // 0-indexed data
//   LazySegTree st(sz(a));
//   st.build(a);                  // or: LazySegTree st; st.build(a);
//   st.update(1, 3, 10);          // add 10 to every element in [1, 3]
//   st.query(0, 4);               // sum over [0, 4]
struct LazySegTree {
  i64 n;
  vi st, lazy;

  LazySegTree() {}
  LazySegTree(i64 size) { init(size); }

  void init(i64 size) {
    n = size;
    st.assign(4 * n + 5, 0);
    lazy.assign(4 * n + 5, 0);
  }

  // Recursively builds the sum tree over a[l..r] under the given node.
  void build(i64 node, i64 l, i64 r, const vi& a) {
    if (l == r) {
      st[node] = a[l];
      return;
    }
    i64 mid = (l + r) / 2;
    build(node * 2, l, mid, a);
    build(node * 2 + 1, mid + 1, r, a);
    st[node] = st[node * 2] + st[node * 2 + 1];
  }

  // Build from a 0-indexed vector covering the whole range.
  void build(const vi& a) {
    init(sz(a));
    build(1, 0, n - 1, a);
  }

  // Push this node's pending lazy add down to its sum and (if not a leaf)
  // its children, then clear it. Called before touching a node in
  // update/query so its stored sum is always up to date on entry.
  void push(i64 node, i64 l, i64 r) {
    if (!lazy[node]) return;

    st[node] += (r - l + 1) * lazy[node];

    if (l != r) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
  }

  // Add val to every element in [ql, qr]. Internal recursive worker over
  // the node covering [l, r].
  void update(i64 node, i64 l, i64 r, i64 ql, i64 qr, i64 val) {
    push(node, l, r);

    if (qr < l || r < ql)
      return;

    if (ql <= l && r <= qr) {
      lazy[node] += val;
      push(node, l, r);
      return;
    }

    i64 mid = (l + r) / 2;

    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);

    st[node] = st[node * 2] + st[node * 2 + 1];
  }

  // Sum over [ql, qr]. Internal recursive worker over the node covering [l, r].
  i64 query(i64 node, i64 l, i64 r, i64 ql, i64 qr) {
    push(node, l, r);

    if (qr < l || r < ql)
      return 0;

    if (ql <= l && r <= qr)
      return st[node];

    i64 mid = (l + r) / 2;

    return query(node * 2, l, mid, ql, qr)
      + query(node * 2 + 1, mid + 1, r, ql, qr);
  }

  // Public entry point: add val to every element in [l, r].
  void update(i64 l, i64 r, i64 val) {
    update(1, 0, n - 1, l, r, val);
  }

  // Public entry point: sum over [l, r].
  i64 query(i64 l, i64 r) {
    return query(1, 0, n - 1, l, r);
  }
};
