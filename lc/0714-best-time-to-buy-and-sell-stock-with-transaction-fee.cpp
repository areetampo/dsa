class Solution {
  public:
  int maxProfit(vector<int>& p, int fee) {
    int res = 0;

    for (int i = 0, mn = 0; i < p.size(); i++) {
      if (p[i] - mn - fee > 0) {
        res += p[i] - mn - fee;
      }
      mn = p[i];
    }

    return res;
  }
};
