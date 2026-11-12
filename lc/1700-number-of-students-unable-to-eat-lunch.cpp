class Solution {
public:
  int countStudents(vector<int>& st, vector<int>& sa) {
    int one = accumulate(st.begin(), st.end(), 0);
    int zero = st.size() - one;
    for (int i = 0; i < sa.size(); ++i) {
      if (sa[i] && !one || !sa[i] &&!zero) return sa.size() - i;
      else if (sa[i]) --one;
      else --zero;
    }  
    return 0;
  }
};