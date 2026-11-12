class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {//customers, grumpy, minutes
        //sliding window of minutes size for max sum of customers[i] where grumpy[i] = 1
        int sum = 0, n = c.size();
        for (int i = 0; i < n; i++) sum += !g[i] || i < m ? c[i] : 0;
        int res = sum;
        for (int i = 0; i < n - m; i++) {
            sum += -g[i] * c[i] + g[i + m] * c[i + m];
            res = max(res, sum);
        }
        return res;
    }
};