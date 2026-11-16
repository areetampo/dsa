class Solution {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        for (int el : nums) max = Math.max(max, el);
        if (max <= 0) return max;

        int currSum = 0; int ans = Integer.MIN_VALUE;
        for (int el : nums) {
            currSum += el;
            if (currSum < 0) currSum = 0;
            ans = Math.max(ans, currSum);
        }
        return ans;
    }
}