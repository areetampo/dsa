class Solution {
    public boolean divideArray(int[] nums) {
        int f[] = new int[501];
        for (int i = 0; i < nums.length; i++) {
            f[nums[i]]++;
        }
        int pairs = 0;
        for (int i = 1; i <= 500; i++) {
            if (f[i] % 2 == 1) return false;
            pairs += f[i] / 2;
        }
        return pairs == nums.length / 2;
    }
}