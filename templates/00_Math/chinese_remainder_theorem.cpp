// Chinese Remainder Theorem (generalized) — given a system x = a_i (mod m_i)
// for possibly NON-coprime moduli, finds x (mod the combined lcm), or
// reports impossible. Uses the extended-Euclidean CRT merge, so moduli
// don't need to be pairwise coprime (unlike the simpler CRT variant that
// only works when they are).
//
// Complexity: O(k log(max modulus)) for k equations.
//
// Usage:
//   CRT crt;
//   vpi eqs = {{2, 3}, {3, 5}, {2, 7}};  // x = 2 (mod 3), x = 3 (mod 5), x = 2 (mod 7)
//   pii ans = crt.solve(eqs);             // {x, combined modulus}, or {-1, -1} if impossible
struct CRT {
  // Extended Euclidean algorithm: finds x, y such that a*x + b*y = gcd(a, b),
  // returning gcd(a, b).
  i64 extgcd(i64 a, i64 b, i64& x, i64& y) {
    if (!b) {
      x = 1;
      y = 0;
      return a;
    }

    i64 x1, y1;
    i64 g = extgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
  }

  // equations = {{remainder, modulus}, ...}. Returns {x, combined modulus},
  // or {-1, -1} if the system has no solution (moduli conflict).
  pii solve(vpi equations) {
    i64 x = 0;
    i64 mod_ = 1;

    for (auto [a, m] : equations) {
      i64 p, q;
      i64 g = extgcd(mod_, m, p, q);

      if ((a - x) % g) return { -1, -1 };

      i64 lcm_ = mod_ / g * m;
      i64 t = ((i128)(a - x) / g * p) % (m / g); // i128 avoids overflow before the mod-reduce

      x += mod_ * t;
      x %= lcm_;
      if (x < 0) x += lcm_;

      mod_ = lcm_;
    }

    return { x, mod_ };
  }
};
