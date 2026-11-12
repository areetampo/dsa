class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        //BCs
        dp[0][0] = true;//"" and "" match already
        for (int i = 1; i <= s.length(); i++) dp[i][0] = false;//s.len > 0 and p = "" -> never match
        //s = "" (i=0) -> j stays false for the ?/char present in p and,
        //p(j-1)=* &&  and prev j dp cell not false then only = true
        for (int j = 1; j <= p.length(); j++) if (p.charAt(j-1) == '*' && dp[0][j-1]) dp[0][j] = true;
        //tabulation
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                if (s.charAt(i-1) == p.charAt(j-1) || p.charAt(j-1) == '?') dp[i][j] = dp[i-1][j-1];
                else if (p.charAt(j-1) == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;//non equal chars
            }
        }
        return dp[s.length()][p.length()];
    }
}

