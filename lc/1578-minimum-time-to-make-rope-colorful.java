class Solution {
    public int minCost(String colors, int[] neededTime) {
        if (colors.length() == 1) return 0;

        int ans = 0;

        int i = 0;
        while (i < colors.length()) {
            int j = i;
            int totalTime = 0, maxTime = -1;
            while (j < colors.length() && colors.charAt(j) == colors.charAt(i)) {
                totalTime += neededTime[j];
                maxTime = Math.max(maxTime, neededTime[j]);
                ++j;
            }
            if (j - i != 1) {
                ans += totalTime - maxTime;
            }
            i = j;
        }

        return ans;
    }
}