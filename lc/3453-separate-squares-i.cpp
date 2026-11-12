class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        sort(sq.begin(), sq.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int n = sq.size();
        double lo = 0, hi = 1e18;
        while (lo <= hi) {
            double mid = lo + (hi - lo) / 2, la = 0, ra = 0;
            for (auto& i : sq) {
                double x = i[0], y = i[1], len = i[2];
                if (y < mid) {
                    if (y + len <= mid)
                        la += len * len;
                    else {
                        la += (mid - y) * len;
                        ra += (y + len - mid) * len;
                    }
                } else {
                    ra += len * len;
                }
            }
            if (la >= ra)
                hi = mid - 0.00001;
            else
                lo = mid + 0.00001;
        }
        return lo;
    }
};