class Solution {
public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long res = 0;
    int i = 0, j = 0;
    long long sum = 0, score = 0;
    while (j < nums.size()) {
      sum += nums[j];
      score = sum * (j - i + 1);
      while (i <= j && score >= k) {
        sum -= nums[i++];
        score = sum * (j - i + 1);
      }
      res += j - i + 1;
      ++j;
    }     
    return res;
  }
};