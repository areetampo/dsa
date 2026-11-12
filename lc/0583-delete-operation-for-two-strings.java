class Solution {
    public int minDistance(String word1, String word2) {
        int dp[][] = new int[word1.length() + 1][word2.length() + 1];
        //BCs (i = 0, j = 0) -> "", "" same only so 0 delete operations
        //(i = 0) s1.len = 0 -> lcs.len = 0 irrespective of s2.len -> delete operations = s2.len
        for (int j = 1; j <= word2.length(); j++) dp[0][j] = word2.substring(0, j).length();
        //(j = 0) s2.len = 0 -> lcs.len = 0 irrespective of s1.len -> delete operations = s1.len
        for (int i = 1; i <= word1.length(); i++) dp[i][0] = word1.substring(0, i).length();
        //tabulation
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + Math.min(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[word1.length()][word2.length()];    
    } 
}