class Solution {
public:
  string makeGood(string s) {
    int n = s.length();
    stack<char> st;
    for (int i = n - 1; i >= 0; --i) {
      if (!st.empty() && abs(st.top() - s[i]) == 32) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
    string res = "";
    while (!st.empty()) {
      res += st.top();
      st.pop();
    }
    return res;
  }
};