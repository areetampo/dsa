#include <bits/stdc++.h>
using namespace std;

/*
    RABIN-KARP STRING MATCHING

    Finds all occurrences of pattern in text using a rolling hash.

    Idea:
    - Hash the pattern.
    - Hash every substring of text having the same length.
    - If hashes match, verify the substring to avoid hash-collision errors.
    - Rolling hash lets us move from one window to the next in O(1).

    Complexity:
    - Expected: O(n + m + number_of_matches * m)
      where n = text.size(), m = pattern.size().
    - With the usual double-hash approach, collisions are extremely unlikely.
    - Extra space: O(1) apart from the returned answer.

    Usage:
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> pos = rabin_karp::find(text, pattern);

        // pos = {2, 5}

    The returned positions are 0-indexed starting positions.

    Notes:
    - This implementation uses two independent moduli to make accidental
      hash collisions extremely unlikely.
    - Actual characters are compared whenever both hashes match, so the
      result is still correct even if a collision somehow occurs.
*/

namespace rabin_karp {

  using ll = long long;

  // Two large primes for double hashing.
  static constexpr ll MOD1 = 1'000'000'007LL;
  static constexpr ll MOD2 = 1'000'000'009LL;

  // Base should be smaller than both moduli.
  static constexpr ll BASE = 911382323LL;

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

    // Empty pattern: choose the common convention of matching
    // at every position from 0 through n.
    if (m == 0) {
      for (int i = 0; i <= n; ++i)
        ans.push_back(i);
      return ans;
    }

    if (m > n)
      return ans;

  /*
      Polynomial hash:

          hash(s) = s[0] * BASE^(m-1)
                 + s[1] * BASE^(m-2)
                 + ...
                 + s[m-1]

      All calculations are done modulo MOD.
  */

    ll pattern_h1 = 0, pattern_h2 = 0;
    ll window_h1 = 0, window_h2 = 0;

    // BASE^(m-1), needed when removing the first character
    // from the current window.
    ll power1 = 1, power2 = 1;

    for (int i = 0; i < m - 1; ++i) {
      power1 = power1 * BASE % MOD1;
      power2 = power2 * BASE % MOD2;
    }

    // Build hash of pattern and first window.
    for (int i = 0; i < m; ++i) {
      ll pc = (unsigned char)pattern[i] + 1;
      ll tc = (unsigned char)text[i] + 1;

      pattern_h1 = (pattern_h1 * BASE + pc) % MOD1;
      pattern_h2 = (pattern_h2 * BASE + pc) % MOD2;

      window_h1 = (window_h1 * BASE + tc) % MOD1;
      window_h2 = (window_h2 * BASE + tc) % MOD2;
    }

    for (int l = 0; l + m <= n; ++l) {

        // Both hashes matching is a very strong indication that
        // the two strings are equal.
      if (window_h1 == pattern_h1 &&
        window_h2 == pattern_h2) {

        /*
            Verify characters as well.

            This makes the function correct even in the extremely
            unlikely event of a double-hash collision.
        */
        bool same = true;

        for (int j = 0; j < m; ++j) {
          if (text[l + j] != pattern[j]) {
            same = false;
            break;
          }
        }

        if (same)
          ans.push_back(l);
      }

      // No next window.
      if (l + m == n)
        break;

    /*
        Roll the window:

        old window:
            text[l ... l+m-1]

        new window:
            text[l+1 ... l+m]

        First remove the contribution of text[l]:

            hash -= text[l] * BASE^(m-1)

        Then shift everything left by one power of BASE:

            hash *= BASE

        Finally add the new character.
    */

      ll old_char = (unsigned char)text[l] + 1;
      ll new_char = (unsigned char)text[l + m] + 1;

      // MOD1
      window_h1 =
        (window_h1 - old_char * power1 % MOD1 + MOD1) % MOD1;

      window_h1 =
        (window_h1 * BASE + new_char) % MOD1;

    // MOD2
      window_h2 =
        (window_h2 - old_char * power2 % MOD2 + MOD2) % MOD2;

      window_h2 =
        (window_h2 * BASE + new_char) % MOD2;
    }

    return ans;
  }

} // namespace rabin_karp


/*
    ------------------------------------------------------------
    USAGE EXAMPLE
    ------------------------------------------------------------

    int main() {
        string text = "ababcabcab";
        string pattern = "abc";

        vector<int> positions = rabin_karp::find(text, pattern);

        for (int pos : positions)
            cout << pos << ' ';

        // Output:
        // 2 5
    }

    If you don't want a namespace, you can simply remove

        namespace rabin_karp { ... }

    and call:

        vector<int> positions = find(text, pattern);

    ------------------------------------------------------------
*/
