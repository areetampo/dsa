class Solution {
  public:
  int alternatingSubarray(vector<int>& a) {
    int n = a.size(), res = -1, dp = -1;
    for (int i = 1; i < n; ++i, res = max(res, dp))
      if (dp > 0 && a[i] == a[i - 2])
        dp++;
      else
        dp = a[i] == a[i - 1] + 1 ? 2 : -1;
    return res;
  }
};
