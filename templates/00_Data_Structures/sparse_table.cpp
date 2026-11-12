// Sparse Table — immutable range minimum query (RMQ), O(1) per query after
// an O(n log n) build. Only works for idempotent operations (min, max, gcd,
// AND, OR — NOT sum, since overlapping the two halves would double-count).
// No updates supported; rebuild from scratch if the array changes.
//
// Complexity: build O(n log n); query O(1).
//
// Usage:
//   vi a = {5, 2, 8, 1, 9, 3};
//   SparseTable st(a);
//   st.query(1, 4);   // min over a[1..4], inclusive both ends
struct SparseTable {
  i64 n, LOG;
  vvi st;    // st[j][i] = min over a[i .. i + 2^j - 1]
  vi lg;     // lg[i] = floor(log2(i)), precomputed for O(1) query

  SparseTable() {}
  SparseTable(const vi& a) { build(a); }

  void build(const vi& a) {
    n = sz(a);

    LOG = 1;
    while ((1LL << LOG) <= n) LOG++; // NOTE: 1LL, not 1 — plain `1 << LOG` would
                                      // overflow int for larger n; this is a
                                      // classic sparse-table bug to avoid.

    st.assign(LOG, vi(n));
    lg.assign(n + 1, 0);

    fo(i, 2, n + 1)
      lg[i] = lg[i / 2] + 1;

    fo(i, 0, n)
      st[0][i] = a[i];

    // st[j][i] combines the two half-length blocks computed at level j-1,
    // covering [i, i + 2^j - 1] by overlapping [i, i+2^(j-1)-1] with
    // [i+2^(j-1), i+2^j-1] — safe to overlap since min is idempotent.
    fo(j, 1, LOG) {
      i64 lim = n - (1LL << j);
      fo(i, 0, lim + 1)
        st[j][i] = min(st[j - 1][i], st[j - 1][i + (1LL << (j - 1))]);
    }
  }

  // Min over [l, r], inclusive both ends.
  i64 query(i64 l, i64 r) {
    i64 j = lg[r - l + 1];
    return min(st[j][l], st[j][r - (1LL << j) + 1]);
  }
};
