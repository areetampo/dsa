#include <bits/stdc++.h>
using namespace std;

/*
    KMP (KNUTH-MORRIS-PRATT) STRING MATCHING

    Finds all occurrences of pattern in text with a guaranteed linear bound.

    Idea:
    - For a string s, pi[i] = length of the longest proper prefix of s[0..i]
      that is also a suffix of s[0..i]  (the "prefix function").
    - While matching, if text[i] fails to extend the current match of length k,
      fall back to k = pi[k-1] instead of restarting. That fall back is the
      longest shorter prefix of the pattern that could still be matching.
    - k only increases by 1 per text character, and each fall back decreases
      it, so the total work is linear.

    Complexity:
    - Time:  O(n + m) worst case, deterministic (no hashing, no collisions).
      where n = text.size(), m = pattern.size().
    - Space: O(m) for the prefix function.

    Usage:
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> pos = kmp::find(text, pattern);

        // pos = {2, 5}

    The returned positions are 0-indexed starting positions.

    Bonus (period tools, handy for repeated string problems):
        kmp::smallest_period("abababab")   // 2
        kmp::primitive_root("abababab")    // "ab"
        kmp::primitive_root("abca")        // "abca"  (period 3 does not divide 4)

    Notes:
    - A string of length n has smallest period n - pi[n-1]. It is a pure
      repetition (s = r^k) only if that period divides n.
*/

namespace kmp {

  /*
      Prefix function.

      Example:
          s  = "abcabca"
          pi = {0, 0, 0, 1, 2, 3, 4}
  */
  vector<int> prefix_function(const string& s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; ++i) {
      int k = pi[i - 1];

      // Fall back through shorter borders until s[i] can extend one.
      while (k > 0 && s[i] != s[k])
        k = pi[k - 1];

      if (s[i] == s[k])
        ++k;

      pi[i] = k;
    }

    return pi;
  }

  /*
      Returns all 0-indexed positions where pattern occurs in text.

      Example:
          text    = "aaaaa"
          pattern = "aa"

          returns {0, 1, 2, 3}
  */
  vector<int> find(const string& text, const string& pattern) {
    int n = (int)text.size();
    int m = (int)pattern.size();

    vector<int> ans;

    // Empty pattern: match at every position from 0 through n
    // (same convention as the Rabin-Karp file).
    if (m == 0) {
      for (int i = 0; i <= n; ++i)
        ans.push_back(i);
      return ans;
    }

    if (m > n)
      return ans;

    vector<int> pi = prefix_function(pattern);

    int k = 0;  // length of the current match

    for (int i = 0; i < n; ++i) {
      while (k > 0 && text[i] != pattern[k])
        k = pi[k - 1];

      if (text[i] == pattern[k])
        ++k;

      if (k == m) {
        ans.push_back(i - m + 1);
        k = pi[k - 1];        // keep going, overlapping matches allowed
      }
    }

    return ans;
  }

  // Smallest p such that s[i] == s[i+p] for all valid i.
  int smallest_period(const string& s) {
    if (s.empty())
      return 0;
    return (int)s.size() - prefix_function(s).back();
  }

  // Smallest block r with s = r^k exactly (s itself if none).
  string primitive_root(const string& s) {
    int n = (int)s.size();
    if (n == 0)
      return s;

    int p = smallest_period(s);
    return (n % p == 0) ? s.substr(0, p) : s;
  }

} // namespace kmp


/*
    ------------------------------------------------------------
    USAGE EXAMPLE
    ------------------------------------------------------------

    int main() {
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> positions = kmp::find(text, pattern);

        for (int pos : positions)
            cout << pos << ' ';

        // Output:
        // 2 5
    }

    If you don't want a namespace, you can simply remove

        namespace kmp { ... }

    and call:

        vector<int> positions = find(text, pattern);

    ------------------------------------------------------------
*/
