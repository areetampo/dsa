class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      while (x <= nums.size() && x > 0 && x != nums[x - 1]) {
        int t = nums[x - 1];
        nums[x - 1] = x;
        x = t;
      }
    }    
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
  }
};