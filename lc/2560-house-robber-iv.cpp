class Solution {
public:
    int minCapability(vector<int>& a, int k) {
        int lo = 1, hi = 1e9, n = a.size();
        if (n == 1) return a[0];
        while (lo <= hi) {
            int c = lo + (hi - lo) / 2;//capability, houses robbed
            // vector<int> dp(n);
            //minimize space, use 2 variables only
            int x = a[0] <= c, y = max(x, (int)(a[1] <= c));
            for (int i = 2; i < n; i++) {
                int t = x;
                x = y;
                y = max(y, t + (a[i] <= c));
            }
            if (y >= k) hi = c - 1;
            else lo = c + 1;
        }
        return lo;
    }
};