#include <bits/stdc++.h>
using namespace std;

/*
    REPEATED STRING MATCH  (is b^y a substring of a^x ?)

    a^x means the string a written x times in a row.
    Lengths can reach 1e11, so the strings can never be built.

    Idea:
    - a^x is a window of the infinite string aaaa...
    - If b^y starts at offset o inside a, then for every i:
          b^y[i] == a[(o + i) mod |a|]
    - Both strings are periodic, so comparisons repeat. Either brute force
      one cycle (small |a|,|b|) or use period theory (any size).

    Two solutions are provided:

    1) match_brute      O(|a| * lcm(|a|,|b|))   about 1e6 for |a|,|b| <= 100
       Try every start offset in a, compare one full cycle of length
       lcm(|a|,|b|). After that cycle every comparison repeats.

    2) match_fine_wilf  O(|a|^2 + |b|^2) with the simple root finder below
       Shrink both to primitive roots, then split on length (see below).

    Usage:
        bool r1 = repeated_match::match_brute("abcd", "cdab", 2, 1);      // true
        bool r2 = repeated_match::match_fine_wilf("abc", "bc", 2, 3);     // false

    Notes:
    - Use long long for lengths: |b| * y can reach 1e11.
    - Only offsets o in [0, |a|) need testing: a match starting at s also
      works at s mod |a| (earlier start, still fits).
*/

namespace repeated_match {

  using ll = long long;

  /*
      ------------------------------------------------------------
      Solution 1: wrap-around brute force
      ------------------------------------------------------------
      At step i we look at the pair (i mod |b|, (o+i) mod |a|).
      Both pointers return to their start together every
      L = lcm(|a|,|b|) steps, so comparing min(L, |b|*y) characters
      decides the whole match.
  */
  bool match_brute(const string& a, const string& b, ll x, ll y) {
    ll n = a.size(), m = b.size();
    ll len_a = n * x, len_b = m * y;

    ll L = n / __gcd(n, m) * m;                // lcm, at most 1e4
    ll check = min(L, len_b);                  // one full cycle is enough

    for (ll o = 0; o < n; ++o) {
      if (o + len_b > len_a)                   // b^y does not fit from o
        break;

      bool ok = true;
      for (ll i = 0; i < check; ++i) {
        if (a[(o + i) % n] != b[i % m]) {
          ok = false;
          break;
        }
      }
      if (ok)
        return true;
    }
    return false;
  }

  /*
      ------------------------------------------------------------
      Primitive root
      ------------------------------------------------------------
      Smallest block r such that s = r^k exactly.

          "abab" -> "ab"
          "abca" -> "abca"   (period 3 does not divide length 4)

      The root length always divides |s|, so a^x = p^X exactly with
      X = x * (|a| / |p|).
  */
  string primitive_root(const string& s) {
    int n = (int)s.size();
    for (int d = 1; d <= n; ++d) {
      // d divides n and s has period d  <=>  s = (s[0..d))^(n/d)
      if (n % d == 0 && s.compare(d, n - d, s, 0, n - d) == 0)
        return s.substr(0, d);
    }
    return s;
  }

  /*
      ------------------------------------------------------------
      Solution 2: primitive roots + Fine-Wilf
      ------------------------------------------------------------
      Let p, q be the roots of a, b with lengths P, Q, and
      len_a = |a|*x, len_b = |b|*y.

      Case 1: len_b > len_a
          Cannot fit. Answer false.

      Case 2: len_b >= P + Q   (long)
          s = q^Y inside p^X has period P (slice of p^X) and period Q
          (q repeated). It is long enough for Fine-Wilf, so it has
          period g = gcd(P,Q). Since q is primitive, g = Q; since the
          first P chars are a rotation of p (primitive), g = P.
          So P == Q and q must be a rotation of p.
          o = (p+p).find(q) is the unique start offset in [0,P), and
          it must still fit: o + len_b <= len_a.

      Case 3: len_b < P + Q    (short, under 200 characters)
          Theorem does not apply. Y < 200, so build B = q^Y, build A
          only up to min(len_a, len_b + P) and use find().

      Fine-Wilf: a string with periods p, q and length >= p + q - gcd(p,q)
      also has period gcd(p,q). Here the simpler bound P+Q is used.
  */
  bool match_fine_wilf(const string& a, const string& b, ll x, ll y) {
    string p = primitive_root(a), q = primitive_root(b);
    ll P = p.size(), Q = q.size();
    ll X = x * ((ll)a.size() / P);
    ll Y = y * ((ll)b.size() / Q);
    ll len_a = P * X, len_b = Q * Y;

    // Case 1
    if (len_b > len_a)
      return false;

    // Case 2
    if (len_b >= P + Q) {
      if (P != Q)
        return false;
      size_t o = (p + p).find(q);
      if (o == string::npos)
        return false;
      return (ll)o + len_b <= len_a;
    }

    // Case 3
    string B;
    for (ll i = 0; i < Y; ++i)
      B += q;

    ll need = min(len_a, len_b + P);
    string A;
    while ((ll)A.size() < need)
      A += p;

    return A.find(B) != string::npos;
  }

} // namespace repeated_match


/*
    ------------------------------------------------------------
    USAGE EXAMPLE  (compile with -DREPEATED_MATCH_DEMO to run it)
    ------------------------------------------------------------
*/
#ifdef REPEATED_MATCH_DEMO
int main() {
  cout << boolalpha;
  cout << repeated_match::match_brute("ab", "abab", 2, 1) << ' '
    << repeated_match::match_fine_wilf("ab", "abab", 2, 1) << '\n';   // true true
  cout << repeated_match::match_brute("abc", "bc", 2, 3) << ' '
    << repeated_match::match_fine_wilf("abc", "bc", 2, 3) << '\n';    // false false
  cout << repeated_match::match_brute("abcd", "cdab", 2, 1) << ' '
    << repeated_match::match_fine_wilf("abcd", "cdab", 2, 1) << '\n'; // true true
  cout << repeated_match::match_brute("ab", "ba", 2, 2) << ' '
    << repeated_match::match_fine_wilf("ab", "ba", 2, 2) << '\n';     // false false

// random check against building the strings literally
  mt19937 rng(7);
  int bad = 0;
  for (int it = 0; it < 200000; ++it) {
    int n = 1 + rng() % 6, m = 1 + rng() % 6;
    string a, b;
    for (int i = 0; i < n; ++i) a += char('a' + rng() % 2);
    for (int i = 0; i < m; ++i) b += char('a' + rng() % 2);
    if (rng() % 2) { string t = a; a.clear(); for (int k = 1 + rng() % 3; k--;) a += t; }
    if (rng() % 2) { string t = b; b.clear(); for (int k = 1 + rng() % 3; k--;) b += t; }
    int x = 1 + rng() % 8, y = 1 + rng() % 8;
    string A, B;
    for (int i = 0; i < x; ++i) A += a;
    for (int i = 0; i < y; ++i) B += b;
    bool e = A.find(B) != string::npos;
    if (repeated_match::match_brute(a, b, x, y) != e ||
      repeated_match::match_fine_wilf(a, b, x, y) != e) ++bad;
  }
  cout << "mismatches: " << bad << '\n';
}
#endif
