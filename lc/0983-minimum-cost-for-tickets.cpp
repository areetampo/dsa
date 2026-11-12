class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& c) {
        int dp[366] = {0};
        for (int i = 1, d = 0; i <= days.back(); i++, d++) {
            while (i < days[d]) {
                dp[i] = dp[i - 1];
                i++;
            }
            dp[i] = min({
                c[0] + dp[i - 1], 
                c[1] + dp[max(i - 7, 0)],
                c[2] + dp[max(i - 30, 0)]});
        }
        return dp[days.back()];
    }
};