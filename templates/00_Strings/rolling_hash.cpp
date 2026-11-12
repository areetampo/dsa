// Double polynomial rolling hash — O(1) substring-hash comparison after an
// O(n) build. Uses two independent moduli to make hash collisions
// astronomically unlikely (relying on just one modulus is a known way to
// get hacked on adversarial test data).
//
// Complexity: build O(n); getHash is O(1) per call.
//
// Usage:
//   RollingHash rh("abcabc");
//   auto h1 = rh.getHash(0, 2);   // hash of "abc" (indices 0..2, inclusive)
//   auto h2 = rh.getHash(3, 5);   // hash of the second "abc"
//   h1 == h2;                      // true -- identical substrings hash equal
//
// NOTE: members renamed hmod1/hmod2 (not mod1/mod2) — the template already
// declares a global `mod1` (998244353, for NTT) with a DIFFERENT value than
// this struct's second hash modulus (1000000009). Keeping the same name
// would silently shadow the global inside this struct and invite confusion.
struct RollingHash {
  const i64 hmod1 = 1000000007;
  const i64 hmod2 = 1000000009;
  const i64 base = 911382323;

  vi h1, h2; // prefix hashes
  vi p1, p2; // powers of base, precomputed for O(1) hash extraction

  RollingHash(string s) {
    i64 n = sz(s);

    h1.assign(n + 1, 0);
    h2.assign(n + 1, 0);
    p1.assign(n + 1, 1);
    p2.assign(n + 1, 1);

    fo(i, 0, n) {
      h1[i + 1] = (h1[i] * base + s[i]) % hmod1;
      h2[i + 1] = (h2[i] * base + s[i]) % hmod2;
      p1[i + 1] = p1[i] * base % hmod1;
      p2[i + 1] = p2[i] * base % hmod2;
    }
  }

  // Hash of s[l..r], inclusive both ends.
  pi getHash(i64 l, i64 r) {
    i64 x1 = (h1[r + 1] - h1[l] * p1[r - l + 1]) % hmod1;
    if (x1 < 0) x1 += hmod1;

    i64 x2 = (h2[r + 1] - h2[l] * p2[r - l + 1]) % hmod2;
    if (x2 < 0) x2 += hmod2;

    return { x1, x2 };
  }
};
