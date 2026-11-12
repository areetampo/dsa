class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = i;
            int setBits = 0;
            while (j != 0) {
                if ((j & 1) == 1) setBits++;
                j = j >> 1;
            }
            if (setBits == k) ans += nums.get(i);
        }
        return ans;
    }
}