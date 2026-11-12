class Solution {
    public int waysToSplitArray(int[] nums) {
        long sum = 0, s = 0;
        for (int i = 0; i < nums.length; i++) sum += nums[i];
        int res = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            s += nums[i];
            sum -= nums[i];
            if (s >= sum) res++;
        }
        return res;
    }
}