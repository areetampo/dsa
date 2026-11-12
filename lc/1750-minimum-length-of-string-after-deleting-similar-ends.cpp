class Solution {
public:
  int minimumLength(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j && s[i] == s[j]) {
      cout << i << " " << j << endl;
      while (i < s.length() - 1 && s[i] == s[++i]) {}
      while (j && s[j] == s[--j]) {}
    }
    return (i <= j) ? j - i + 1 : 0;
    //cabaabac
    //   ij
  }
};