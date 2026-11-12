class Solution {
public:
    int dfs(int n, vector<int>& dp) {
        if (dp[n] != 1e9) return dp[n];
        for (int i = 1; i * i <= n; ++i) {
            dp[n] = min(dp[n], 1 + dfs(n - i * i, dp));
        }
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        return dfs(n, dp);
    }
};
//bfs
// queue<pair<int, int>> q;
// unordered_set<int> s;//don't vis the nums alr added in q earlier since 
// //they will have less numsUsed from the time they appeared previously
// q.push({0, n});
// while (!q.empty()) {
//     int numsUsed = q.front().first, remainder = q.front().second; q.pop();
//     cout << numsUsed << " " << remainder << endl;
//     if (!remainder) return numsUsed;
//     else {
//         int i = 1;
//         while (i * i <= remainder) {
//             if (s.find(remainder - i * i) == s.end()) {
//                 q.push({numsUsed + 1, remainder - i * i});
//                 s.insert(remainder - i * i);
//             }
//             ++i;
//         }
//     }
// }
// return n;