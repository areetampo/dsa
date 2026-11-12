class Solution {//560 O(n) map space, optimize: sliding window O(1) space
public:
  int sumAtMostK(vector<int>& v, int k) {
    int res = 0;//total subarrays
    int i = 0, j = -1, sum = 0;
    while (++j < v.size()) {
      sum += v[j];
      while (i <= j && sum > k) {
        sum -= v[i++];
      }
      if (sum <= k)  res += j - i + 1;
    }
    return res;
  }
  int numSubarraysWithSum(vector<int>& v, int k) {//sliding window
    return sumAtMostK(v, k) - sumAtMostK(v, k - 1);
  }
};//sliding window with a 1 1 to a 1 on right so sum of 1s = k, then calc 0s in left, right
// int res = 0;
// int i = 0, j = 0, sum = 0;

// if (k == 0) {//different case
//   while (i < n) {
//     while (i < n && nums[i]) ++i;
//     j = i;
//     while (j < n && !nums[j]) { ++j; }
//     res += (j - i) * (j - i + 1) / 2;
//     i = j;
//   }
//   return res;
// }

// i = nums[0] ? -1 : 0; j = -1; 
// while (j + 1 < n && k) k -= nums[++j];//j at last 1 in end
// if (j == n - 1 && k) return 0;//sum < k
// while (j < n) {
//   int left0 = 1, right0 = 1;
//   while (j + right0 < n && !nums[j + right0]) ++right0;
//   j += right0;//at next 1 now
//   //for i:
//   //at next 0 now after a 1 since j put on next 1 so sum = k + 1 -> i put after a 1 so sum = k again
//   //OR at next 1 now if no 0s eg: 0 1 1 1 1 amd goal = 3
//   if (i == -1) i = 1;
//   else if (nums[i]) ++i;
//   else {
//     while (!nums[i++]) ++left0;
//   }
//   res += left0 * right0;
// }

// return res;