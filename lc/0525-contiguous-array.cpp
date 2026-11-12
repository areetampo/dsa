class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    //sssume 0 as -1 and determine longest subarray with 0 sum
    unordered_map<int, int> m;//presum, corresponding idx (always keep leftmost for max len)
    m[0] = -1;//initial case if whole arr len is anwer
    int runningSum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      runningSum += nums[i] ? 1 : -1;
      if (m.count(runningSum)) {//leftmost idx of prev sums kept
        res = max(res, i - m[runningSum]);
      } else {//add new sums only
        m[runningSum] = i;
      }
    }
    return res;
  }
};