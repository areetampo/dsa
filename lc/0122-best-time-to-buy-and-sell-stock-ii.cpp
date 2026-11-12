class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        for (int i = 1, mn = p[0]; i < p.size(); i++) {
            if (p[i] > mn) {
                res += p[i] - mn;
                mn = p[i];
            } else mn = min(mn, p[i]);
            cout << mn << "\n";
        }
        return res;
    }
};