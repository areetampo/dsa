class Solution {
    public int maxSum(int[] nums) {
        int ans = -1;
        for (int i = 0; i < nums.length-1; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (maxDig(nums[i]) == maxDig(nums[j]))
                    ans = Math.max(ans, nums[i] + nums[j]);
            }
        }
        return ans;
    }
    public static int maxDig(int n) {
        int max = -1;
        while (n > 0) {
            int r = n % 10;
            max = Math.max(max, r);
            n /= 10;
        }
        return max;
    }
}