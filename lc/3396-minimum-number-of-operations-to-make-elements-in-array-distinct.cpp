class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int f[101] = {}, n = nums.size();
        for (int i = n - 1; i > (n / 3) * 3 - 1; i--) {
            if (++f[nums[i]] == 2) return n / 3 + 1;
        }
        for (int i = (n / 3) * 3 - 1; i >= 0; i -= 3) {
            if (++f[nums[i]] == 2 || ++f[nums[i - 1]] == 2 || ++f[nums[i - 2]] == 2) {
                return (i + 1 + 1) / 3;
            }
        }
        return 0;
    }
};