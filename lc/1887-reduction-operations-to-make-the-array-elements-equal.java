class Solution {
    public int reductionOperations(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int ans = 0;
        int i = n-1;
        while (nums[i] != nums[0]) {
            while (nums[i] == nums[i-1]) {
                --i;
            }
            ans += n-i;
            --i;
        }
        return ans;
    }
}