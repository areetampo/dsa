class Solution {
    public int minDistance(String word1, String word2) {
        int dp[][] = new int[word1.length() + 1][word2.length() + 1];
        //BCs - (i = 0, j = 0) stays 0 as no steps req to make "" -> ""
        for (int j = 1; j <= word2.length(); j++) dp[0][j] = j;//str1 len = 0 (i = 0) -> include chars = length of str2
        for (int i = 1; i <= word1.length(); i++) dp[i][0] = i;//str2 len = 0 (j = 0) -> include chars = length of str1
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i-1) == word2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = 1 + Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]));
            }
        }
        return dp[word1.length()][word2.length()];
    }
}