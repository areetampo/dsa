class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') st.push(i);
      if (s[i] == ')') {
        if (!st.empty() && s[st.top()] == '(') st.pop();
        else st.push(i);
      }
    }     
    string res = "";
    int i = n;
    while (--i >= 0) {
      if (!st.empty() && st.top() == i) st.pop();
      else res += s[i];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};