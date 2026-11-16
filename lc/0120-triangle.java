class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        dp[0] = triangle.get(0).get(0);

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] + triangle.get(i).get(i);

            for (int j = i-1; j > 0; --j) {
                dp[j] = triangle.get(i).get(j) + Math.min(dp[j-1], dp[j]);
            }

            dp[0] += triangle.get(i).get(0);
        }

        int ans = Integer.MAX_VALUE;
        for (int el : dp) {
            ans = Math.min(ans, el);
        }

        return ans;
    }
}