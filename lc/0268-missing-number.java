class Solution {
    public int missingNumber(int[] nums) {
        int s = (nums.length + 1) * nums.length / 2;
        for (int i = 0; i < nums.length; i++) {
            s -= nums[i];
        }
        return s;
    }
}