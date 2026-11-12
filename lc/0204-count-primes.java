class Solution {
    public int countPrimes(int n) {
        int ans = 0;
        boolean[] nums = new boolean[n];//till n-1 required
        for (int i = 2; i <= Math.sqrt(n-1); ++i) {
            if (nums[i]) continue;//little optimization
            for (int j = 2*i; j < n; j += i) {
                nums[j] = true;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (!nums[i]) ans++;//unmarked = prime
        }
        return ans;
    }
}