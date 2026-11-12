class Solution {
    public int climbStairs(int n) {
        //tabulation
        int[] s = new int[n+1];
        s[0] = 1; s[1] = 1; 
        for (int i = 2; i <= n; i++) {
            s[i] = s[i-1] + s[i-2];
        }
        return s[n];
    }
}
//memoization 
// static int[] s = new int[45+1];
// public int climbStairs(int n) {
//     if (n == 0 || n == 1) return 1;
//     if (s[n] != 0) return s[n]; 
//     s[n] = climbStairs(n-1) + climbStairs(n-2);
//     return s[n];
// }