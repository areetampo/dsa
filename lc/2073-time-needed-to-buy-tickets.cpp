class Solution {
public:
  int timeRequiredToBuy(vector<int>& t, int k) {
    int res = 0;
    int x = t[k];
    for (int i = 0; i < t.size(); ++i) {
      res += min(x + (i <= k ? 0 : -1), t[i]);
    }
    return res;
  }
};