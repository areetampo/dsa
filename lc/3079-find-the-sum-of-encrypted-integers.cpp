class Solution {
public:
  int mxDigit(int x) {
    int res = 0;
    while (x) {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}

    int sumOfEncryptedInt(vector<int>& nums) {
        int res = 0;
      for (int i = 0; i < nums.size(); ++i) {
        int digits = log10(nums[i]) + 1;
        int largest = mxDigit(nums[i]);
        int x = 0;
        while (digits--) {
          x = x * 10 + largest;
        }
        res += x;
        
      }
      return res;
    }
};