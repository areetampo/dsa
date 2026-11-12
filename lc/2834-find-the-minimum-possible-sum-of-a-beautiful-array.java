class Solution {
    public long minimumPossibleSum(int n, int target) {
        long ans = 0;
        if (n <= target/2) {
            for (int i = 1; i <= n; i++) ans += i;
        }
        else {
            for (int i = 1; i <= target/2; i++) ans += i;
            int t = target;
            for (int i = 1; i <= n-target/2; i++) ans += t++;
            
        }
        return ans;
    }
}