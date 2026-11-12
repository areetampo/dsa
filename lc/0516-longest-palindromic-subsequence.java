class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        //find longest common subsequence in both reverse of s, s
        
        int[][] dp = new int[n + 1][n + 1];
        //BCs 
        //i = 0  means s1.len = 0 -> 0 len of lcs irrespective of s2 size
        //j = 0  means s2.len = 0 -> 0 len of lcs irrespective of s1 size

        for (int i = 1; i <= n; i++) {//iterating length of s
            for (int j = 1; j <= n; j++) {//iterating length of reverse s
                if (s.charAt(i-1) == s.charAt(n-j)) 
                dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n];



    }
}