class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> res;
      int s = 0, e = nums.size() - 1;
      while (s <= e) {
        if (abs(nums[s]) < abs(nums[e])) {
          res.push_back(nums[e] * nums[e]);
          --e;
        } else {
          res.push_back(nums[s] * nums[s]);
          ++s;
        }
      } 
      reverse(res.begin(), res.end());
      return res;
    }
};