class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& ss, vector<vector<int>>& ts) {
        //ss[day][city] = stay values, ts[city][new city] = travel values
  vector<vector<int>> dp(k + 1, vector<int>(n, 0));
  for (int day = 0; day < k; day++) {
    for (int newCity = 0; newCity < n; newCity++) {
      for (int city = 0; city < n; city++) {
        dp[day + 1][newCity] = max(dp[day + 1][newCity], dp[day][city] + (newCity == city ? ss[day][newCity] : ts[city][newCity]));
      }
    }
  }
//   dbg(dp);
  return *max_element(dp[k].begin(), dp[k].end());
    }
};