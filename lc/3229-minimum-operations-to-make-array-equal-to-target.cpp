class Solution {
  public:
  long long minimumOperations(vector<int>& nums, vector<int>& target) {
    int n = nums.size();
    long long res = 0, prev = 0;

    for (int i = 0; i < n; i++) {
      long long d = (long long)target[i] - nums[i];
      if (d > prev) res += d - prev;
      prev = d;
    }

    // diff[n-1] = prev, diff[n] = 0
    if (prev < 0) res += -prev;
    return res;
  }
};
