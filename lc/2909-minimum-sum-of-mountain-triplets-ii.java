class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] leftMin = new int[n];
        leftMin[0] = nums[0];
        int[] rightMin = new int[n];
        rightMin[n-1] = nums[n-1];
        for (int i = 1; i < n-1; ++i) {
            leftMin[i] = Math.min(leftMin[i-1], nums[i]);
            rightMin[n-1-i] = Math.min(rightMin[n-i], nums[n-1-i]);
        }
        leftMin[n-1] = Math.min(leftMin[n-2], nums[n-1]);
        rightMin[0] = Math.min(rightMin[1], nums[0]);
        
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i < n-1; ++i) {
            if (leftMin[i-1] < nums[i] && rightMin[i+1] < nums[i])
            ans = Math.min(ans, nums[i] + leftMin[i-1] + rightMin[i+1]);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
        
    }
}