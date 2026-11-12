class Solution {
public:
    int dfs(int i, unordered_map<int, int>& g, vector<int>& dp, int k) {
        if (!g[i]) return 1;
        if (dp[i]) return dp[i];
        //skip + take
        return dp[i] = dfs(i + k, g, dp, k) + (pow(2, g[i]) - 1) * dfs(i + 2 * k, g, dp, k);
    }
    int subsetsFromGroup(unordered_map<int, int>& g, vector<int>& dp, int k) {
        int mn = INT_MAX;
        for (auto i = g.begin(); i != g.end(); i++) mn = min(mn, i->first);
        return dfs(mn, g, dp, k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {//neetcode optimal sol
        unordered_map<int, int> master;
        for (int i : nums) master[i]++;
        int res = 1;
        vector<int> dp(1001, 0);
        for (int i : nums) {
            if (master[i]) {
                unordered_map<int, int> group;
                int f = 0;
                while (master[i + f * k]) {
                    group[i + f * k] = master[i + f * k];
                    master[i + f * k] = 0;
                    f++;
                }
                f = -1;
                while (master[i + f * k]) {
                    group[i + f * k] = master[i + f * k];
                    master[i + f * k] = 0;
                    f--;
                }
                for (auto j = group.begin(); j != group.end(); j++) cout << j->first << " " << j->second << ", "; 
                cout << endl;
                res *= subsetsFromGroup(group, dp, k);
                cout << res << endl;
            }
        }
        return res - 1;//-1 for empty subset
    }
};