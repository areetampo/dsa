class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mn = 0, ans = 0;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] > p[mn]) ans = max(ans, p[i] - p[mn]);
            else mn = i;
        }
        return ans;
    }
};