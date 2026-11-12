class Solution {
public:
  string removeStars(string s) {
    stack<char> S;
    int i = 0;
    while (i < s.size()) {
      if (s[i] == '*') S.pop();
      else S.push(s[i]);
      ++i;
    }     
    string res = "";
    while (!S.empty()) { res += S.top(); S.pop(); }
    reverse(res.begin(), res.end());
    return res;
  }
};