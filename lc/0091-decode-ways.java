class Solution {
    public int numDecodings(String s) {
        // if (s.length() == 1) return (s.charAt(0) == '0') ? 0 : 1;
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        dp[1] = (s.charAt(0) == '0') ? 0 : 1;
        for (int i = 2; i < dp.length; ++i) {
            int oneDigit = s.charAt(i-1) - '0';
            int twoDigit = Integer.parseInt(s.substring(i-2, i));
            dp[i] += (oneDigit != 0) ? dp[i-1] : 0;
            dp[i] += (9 < twoDigit && twoDigit < 27) ? dp[i-2] : 0;
        }
        return dp[s.length()];
    }
}