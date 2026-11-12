class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int res = 0;
    int i = 0, j = 0, product = 1;
    while (j < nums.size()) {
      product *= nums[j];
      while (i <= j && product >= k) {
        product /= nums[i++];
      }
      res += j - i + 1;
      ++j;
    }     
    return res;
  }
};