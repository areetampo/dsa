class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        for (auto& i : units) sort(i.begin(), i.end());
        long long res = 0;
        int mn_0 = 1e5 + 1, mn_1 = 1e5 + 1;
        for (int i = 0; i < units.size(); i++) {
            if (units[i].size() == 1) {
                res += units[i][0]; continue;
            }
            res += units[i][1];
            mn_0 = min(mn_0, units[i][0]);
            mn_1 = min(mn_1, units[i][1]);
        }
        return res - (mn_1 == 1e5 + 1 ? 0 : mn_1) + (mn_0 == 1e5 + 1 ? 0 : mn_0);
    }
};