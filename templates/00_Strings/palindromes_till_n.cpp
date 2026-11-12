// Palindromes up to n — generate by mirroring the first half of the digits.
//
// For a palindrome of length d, only the first ceil(d / 2) digits
// are needed. Mirror them to construct the full palindrome.
//
// Odd length:  abc -> abcba  (don't mirror the middle digit)
// Even length: abc -> abccba (mirror the whole first half)
//
// Complexity: O(number of palindromes <= n * digits(n)).
// Memory: O(number of palindromes <= n) for the returned vector.
//
// Usage:
//   vi p = palindromes(1000);
//   // p = [1, 2, ..., 9, 11, 22, ..., 99, 101, ..., 999]
//
// NOTE: Uses i64, so n should fit in i64. The function includes 0
// separately. If you don't want 0, remove p.pb(0).
// If n is guaranteed to be reasonably small enough that 10^digits
// never overflows i64, the function above is directly usable.

i64 make_pal(i64 x, bool odd) {
  i64 res = x;

  // For odd length, the last digit is the middle digit, so it must not be mirrored.
  if (odd) x /= 10;

  while (x > 0) {
    res = res * 10 + x % 10;
    x /= 10;
  }

  return res;
}

// Get all palindromic numbers in [0, n], sorted increasingly.
vi palindromes(i64 n) {
  vi p;
  if (n < 0) return p;

  // p.pb(0); // no 0

  // Generate palindromes for every possible digit length.
  for (i64 d = 1; ; d++) {
    i64 half = (d + 1) / 2;

    // Smallest first-half value for this digit length.
    i64 lo = 1;
    fo(i, 1, half) lo *= 10;

    // Largest first-half value.
    i64 hi = lo * 10 - 1;

    // Prevent overflow / stop once this length is impossible.
    if (lo > n && d > 1) break;

    for (i64 x = lo; x <= hi; x++) {
      i64 pal = make_pal(x, d & 1);

      if (pal > n) break;
      p.pb(pal);

      // Avoid x++ overflow at i64 limit.
      if (x == hi) break;
    }
  }

  return p;
}
