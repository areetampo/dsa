class Solution {
public:
    bool isSubstringPresent(string s) {
      if (s.length() == 1) return 0;
        string r = "";
      for (int i = s.length() - 1; i >= 0; --i) r += s[i];
        unordered_set<string> set;
      for (int i = 0; i < s.length() - 1; ++i) {
        set.insert(s.substr(i, 2));
      }
      for (int i = 0; i < r.length() - 1; ++i) {
        if (set.find(r.substr(i, 2)) != set.end()) return 1;
      }
      return 0;
    }
};