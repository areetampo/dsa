// Plain Segment Tree — point updates, range sum queries. 0-indexed: build/
// update/query all take positions/ranges in 0..n-1. Simpler and slightly
// faster than LazySegTree when you only ever need to update single elements
// (no range adds) — reach for LazySegTree instead if you need range updates.
//
// Complexity: build is O(n); update/query are both O(log n) per call.
//
// Usage:
//   vi a = {1, 2, 3, 4, 5};
//   SegTree st(sz(a));
//   st.build(a);              // or: SegTree st; st.build(a);
//   st.update(2, 100);         // set a[2] = 100
//   st.query(0, 4);            // sum over [0, 4]
struct SegTree {
  i64 n;
  vi st;

  SegTree() {}
  SegTree(i64 size) { init(size); }

  void init(i64 size) {
    n = size;
    st.assign(4 * n + 5, 0);
  }

  // Recursively builds the sum tree over a[l..r] under the given node.
  void build(i64 node, i64 l, i64 r, const vi& a) {
    if (l == r) {
      st[node] = a[l];
      return;
    }
    i64 mid = l + (r - l) / 2;
    build(node * 2, l, mid, a);
    build(node * 2 + 1, mid + 1, r, a);
    st[node] = st[node * 2] + st[node * 2 + 1];
  }

  // Build from a 0-indexed vector covering the whole range.
  void build(const vi& a) {
    init(sz(a));
    build(1, 0, n - 1, a);
  }

  // Set a[idx] = val. Internal recursive worker over the node covering [l, r].
  void update(i64 node, i64 l, i64 r, i64 idx, i64 val) {
    if (l == r) {
      st[node] = val;
      return;
    }
    i64 mid = l + (r - l) / 2;
    if (idx <= mid)
      update(node * 2, l, mid, idx, val);
    else
      update(node * 2 + 1, mid + 1, r, idx, val);

    st[node] = st[node * 2] + st[node * 2 + 1];
  }

  // Public entry point: set a[idx] = val.
  void update(i64 idx, i64 val) {
    update(1, 0, n - 1, idx, val);
  }

  // Sum over [ql, qr]. Internal recursive worker over the node covering [l, r].
  i64 query(i64 node, i64 l, i64 r, i64 ql, i64 qr) {
    if (qr < l || r < ql)
      return 0;

    if (ql <= l && r <= qr)
      return st[node];

    i64 mid = l + (r - l) / 2;

    return query(node * 2, l, mid, ql, qr)
      + query(node * 2 + 1, mid + 1, r, ql, qr);
  }

  // Public entry point: sum over [l, r].
  i64 query(i64 l, i64 r) {
    if (l > r) return 0;
    return query(1, 0, n - 1, l, r);
  }
};
