class Solution {
    public int minimumSum(int n, int k) {
        int ans = 0;
        
        if (n <= k/2) {
            for (int i = 1; i <= n; i++) {
                ans += i;
            }
            return ans;
        }
        
        for (int i = 1; i <= k/2; i++) {
            ans += i;
        }
        int j = k;
        for (int i = 1; i <= n - k/2; i++) {
            ans += j++; 
        }
        return ans;
    }
}