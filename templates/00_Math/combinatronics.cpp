// nCr/nPr — modular (mod MOD) and small-exact variants. Call
// precomp_factorials() once before using C()/P(); C_exact()/P_exact() are
// self-contained and don't need it.
//
// Complexity: precomp_factorials() is O(MAXN), one-time; C/P are O(1) each
// after that; C_exact/P_exact are O(r) each, no precomp needed.
//
// Usage:
//   precomp_factorials();   // put this inside precomp()
//   C(5, 2);           // 10, mod MOD (the template's MOD constant)
//   P(5, 2);           // 20, mod MOD
//   C_exact(10, 3);    // 120, exact (no mod), only safe for n <= ~60
//   Mint(C(5, 2));     // wrap the result if you want to keep working in Mint
//
// NOTE: MAXN is guarded with #ifndef so this can be safely pasted alongside
// sieve.cpp (which also defines MAXN) without a duplicate-definition error —
// whichever file gets pasted first "wins" and sets the shared value. Bump
// the number below if a problem needs a larger n than 2e6.
#ifndef MAXN
#define MAXN 2000005
#endif
i64 fact[MAXN], inv_fact[MAXN];
void precomp_factorials() {
  fact[0] = 1;
  fo(i, 1, MAXN) fact[i] = fact[i - 1] * i % MOD;
  inv_fact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD);
  fr(i, MAXN - 2, 0) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

// nCr mod p — number of ways to choose r from n (requires precomp_factorials)
i64 C(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

// nPr mod p — number of ways to arrange r from n (requires precomp_factorials)
// nPr = n! / (n-r)!
i64 P(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  return fact[n] * inv_fact[n - r] % MOD;
}

// nCr exact (no mod) — only safe for small n (n <= ~60); returns -1 on overflow
i64 C_exact(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  if (r > n - r) r = n - r;
  i64 res = 1;
  fo(i, 0, r) {
    if (res > (i64)9e18 / (n - i)) return -1;
    res = res * (n - i) / (i + 1);
  }
  return res;
}

// nPr exact (no mod) — only safe for very small n (n <= ~20); returns -1 on overflow
i64 P_exact(i64 n, i64 r) {
  if (r < 0 || r > n) return 0;
  i64 res = 1;
  fo(i, 0, r) {
    if (res > (i64)9e18 / (n - i)) return -1;
    res *= (n - i);
  }
  return res;
}
