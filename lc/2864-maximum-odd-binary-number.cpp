class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      sort(s.rbegin(), s.rend());
      for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == '1') {
          swap(s[i], s[s.length() - 1]);
          break;
        }
      }
      return s;
    }
};