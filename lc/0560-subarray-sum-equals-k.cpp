class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;
    unordered_map<int, int> m;//presum, num of occurence of that presum
    int presum = 0;
    m[0] = 1;//eg k = 0 and arr = [0,0,0]
    for (int &i : nums) {
      presum += i;
      // if (m.count(presum - k)) res += m[presum - k]; or directly
      res += m[presum - k];
      ++m[presum];
    }
    return res;
  }
};