// Matrix exponentiation — raise an n x n matrix to a power mod p in
// O(n^3 log(exp)) via repeated squaring. Classic tool for computing the
// k-th term of a linear recurrence (Fibonacci, tiling counts, etc.) in
// O(log k) instead of O(k).
//
// Complexity: multiply is O(n^3); power is O(n^3 log(exp)).
//
// Usage (Fibonacci via [[1,1],[1,0]]^k):
//   Matrix M(2);                    // defaults to mod MOD (the template's MOD constant)
//   M.a = {{1, 1}, {1, 0}};
//   Matrix Mk = M.power(k);
//   i64 fibK = Mk.a[0][1];
//   Matrix M2(2, MOD2);             // or pass any other modulus as the second argument
//
// Entries should be in [0, mod) and mod should stay below ~3e9 (products must fit in i64).
struct Matrix {
  i64 n, mod;
  vvi a;

  Matrix() {}

  Matrix(i64 n, i64 m = MOD) : n(n), mod(m) {
    a.assign(n, vi(n, 0));
  }

  static Matrix identity(i64 n, i64 m = MOD) {
    Matrix I(n, m);
    fo(i, 0, n) I.a[i][i] = 1;
    return I;
  }

  Matrix operator*(const Matrix& o) const {
    Matrix res(n, mod);

    fo(i, 0, n) {
      fo(k, 0, n) {
        if (!a[i][k]) continue; // skip zero entries, common in sparse recurrence matrices
        fo(j, 0, n) {
          res.a[i][j] = (res.a[i][j] + a[i][k] * o.a[k][j]) % mod;
        }
      }
    }

    return res;
  }

  Matrix power(i64 exp) const {
    Matrix base = *this;
    Matrix res = identity(n, mod);

    while (exp) {
      if (exp & 1)
        res = res * base;
      base = base * base;
      exp >>= 1;
    }

    return res;
  }
};
