class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = 0;
    for (auto &i : nums) mx = max(mx, i);

    int i = 0, j = 0, prevFreq = 0, freq = 0, n = nums.size();
    long long res = 0;
    while (j++ < n) {
      prevFreq = freq;
      if (nums[j - 1] == mx) ++freq;
      if (freq >= k) {
        if (prevFreq < freq) {
          while (nums[i++] != mx){}
        }
        res += i;
      }
    }
    //1 4 2 3 4 4 2
    //  i     j     +2
    //        i j   +5
    //        i   j +5 = 12 res
    
    return res;
  }
};