class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mp1, mp2;
    for (int i = 0; i < s.length(); ++i) {
      if (mp1.find(s[i]) == mp1.end()) mp1[s[i]] = t[i];
      else if (t[i] != mp1[s[i]]) return 0;
      if (mp2.find(t[i]) == mp2.end()) mp2[t[i]] = s[i];
      else if (s[i] != mp2[t[i]]) return 0;
    }
    return 1;
  }
};