class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) return true;
        boolean dp[] = new boolean[nums.length];
        dp[0] = true;
        for (int i = 0; i < nums.length; i++) {
            if (dp[i]) {//that idx reachable
                for (int j = 1; j <= nums[i]; j++) {
                    dp[i+j] = true;
                    if (i+j == nums.length - 1) return true;
                } 
            }
            else return false;
        }
        return false;
    }
}