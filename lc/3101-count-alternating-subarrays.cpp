class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);
        long long res = 0;
        int i = 0, j = -1;
        while (++j < n) {
            // cout << i << " " << j << " ";
            if (j > 0 && nums[j] != nums[j - 1]) res += j - i + 1;
            else {
                i = j;
                ++res;
            }
            // cout << res << endl;
        }
        return res;
    }
};