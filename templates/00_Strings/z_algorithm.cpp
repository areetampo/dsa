#include <bits/stdc++.h>
using namespace std;

/*
    Z-FUNCTION STRING MATCHING

    Finds all occurrences of pattern in text with a guaranteed linear bound.

    Idea:
    - For a string s, z[i] = length of the longest common prefix of s and
      the suffix s[i..].   (z[0] is defined as n here.)
    - To search, build  pattern + SEPARATOR + text  and compute z on it.
      Any position i in the text part with z[i] == m is an occurrence,
      because the separator stops a match from running past the pattern.
    - Computing z in linear time uses a window [l, r) that is the rightmost
      segment known to match a prefix. Positions inside the window reuse
      earlier z values instead of comparing again.

    Complexity:
    - Time:  O(n + m) worst case, deterministic.
      where n = text.size(), m = pattern.size().
    - Space: O(n + m) for the combined string and z array.

    Usage:
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> pos = z_function::find(text, pattern);

        // pos = {2, 5}

    The returned positions are 0-indexed starting positions.

    Bonus (period tools, handy for repeated string problems):
        z_function::smallest_period("abababab")   // 2
        z_function::primitive_root("abababab")    // "ab"
        z_function::primitive_root("abca")        // "abca"

    Notes:
    - The separator is a value outside the character range (an int, not a
      char), so the search is correct for any byte values in the strings.
    - s has period p exactly when p + z[p] == n.
*/

namespace z_function {

  /*
      Z array of a sequence of ints.

      Example:
          s = "aabcaab"
          z = {7, 1, 0, 0, 3, 1, 0}
  */
  vector<int> z_array(const vector<int>& s) {
    int n = (int)s.size();
    vector<int> z(n, 0);

    if (n == 0)
      return z;

    z[0] = n;

    // [l, r) is the rightmost segment that matches a prefix of s.
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {

      // Inside the window: reuse the value from the matching prefix position.
      if (i < r)
        z[i] = min(r - i, z[i - l]);

      // Try to extend past what is already known.
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];

      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }

    return z;
  }

  // Convenience wrapper for strings.
  vector<int> z_of_string(const string& s) {
    vector<int> v(s.size());
    for (size_t i = 0; i < s.size(); ++i)
      v[i] = (unsigned char)s[i];
    return z_array(v);
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

    // pattern + SEPARATOR + text, with the separator outside 0..255.
    vector<int> s;
    s.reserve(m + 1 + n);

    for (char c : pattern)
      s.push_back((unsigned char)c);

    s.push_back(-1);

    for (char c : text)
      s.push_back((unsigned char)c);

    vector<int> z = z_array(s);

    for (int i = 0; i < n; ++i) {
      if (z[m + 1 + i] == m)
        ans.push_back(i);
    }

    return ans;
  }

  // Smallest p such that s[i] == s[i+p] for all valid i.
  int smallest_period(const string& s) {
    int n = (int)s.size();
    if (n == 0)
      return 0;

    vector<int> z = z_of_string(s);

    for (int p = 1; p < n; ++p) {
      if (p + z[p] == n)
        return p;
    }

    return n;
  }

  // Smallest block r with s = r^k exactly (s itself if none).
  string primitive_root(const string& s) {
    int n = (int)s.size();
    if (n == 0)
      return s;

    int p = smallest_period(s);
    return (n % p == 0) ? s.substr(0, p) : s;
  }

} // namespace z_function


/*
    ------------------------------------------------------------
    USAGE EXAMPLE
    ------------------------------------------------------------

    int main() {
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> positions = z_function::find(text, pattern);

        for (int pos : positions)
            cout << pos << ' ';

        // Output:
        // 2 5
    }

    If you don't want a namespace, you can simply remove

        namespace z_function { ... }

    and call:

        vector<int> positions = find(text, pattern);

    ------------------------------------------------------------
*/
