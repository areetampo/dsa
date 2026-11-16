class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
          int j = i;
          int x = nums[j];
          while (j + 1 < nums.size() && x < k) {
            x |= nums[++j];
          }
          if (x >= k) res = min(res, j - i + 1);
        }
        return res == INT_MAX ? -1 : res;
        
    }
};