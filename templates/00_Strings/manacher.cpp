// Manacher's algorithm — finds the radius of the longest palindrome
// centered at every position, for both odd-length (d1) and even-length
// (d2) palindromes, in linear time.
//   d1[i] = radius of the longest odd-length palindrome centered at i
//           (palindrome length = 2*d1[i] - 1)
//   d2[i] = radius of the longest even-length palindrome centered between
//           i-1 and i (palindrome length = 2*d2[i])
//
// Complexity: O(n).
//
// Usage:
//   Manacher m("abaaba");
//   m.d1[2];   // longest odd palindrome centered at index 2
//   m.d2[3];   // longest even palindrome centered between index 2 and 3
struct Manacher {
  vi d1, d2;

  Manacher(string s) {
    i64 n = sz(s);
    d1.assign(n, 0);
    d2.assign(n, 0);

    // odd-length palindromes
    i64 l = 0, r = -1;
    fo(i, 0, n) {
      i64 k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

      while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
        k++;

      d1[i] = k--;

      if (i + k > r) {
        l = i - k;
        r = i + k;
      }
    }

    // even-length palindromes
    l = 0; r = -1;
    fo(i, 0, n) {
      i64 k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

      while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
        k++;

      d2[i] = k--;

      if (i + k > r) {
        l = i - k - 1;
        r = i + k;
      }
    }
  }
};
