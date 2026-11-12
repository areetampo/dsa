class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      cout << i << " " << nums[i] - 1 << endl;
      if (nums[abs(nums[i]) - 1] < 0) res.push_back(abs(nums[i]));
      //each duplicate 2 times only so redoing flag will convert it to +ve
      nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }    
    return res;
  }
};