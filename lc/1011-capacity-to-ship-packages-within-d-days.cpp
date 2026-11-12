class Solution {
private: 
    bool canShip(const vector<int> &weights, int days, int thresholdWt) {
        int Days = 0, curr = 0;
        for (int i = 0; i < weights.size(); ++i) {
            curr += weights[i];
            if (curr > thresholdWt) {
                curr = 0;
                i--;
                Days++;
            }
            if (Days > days) return false;
        }
        return ++Days <= days;//for the last shipment
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, h = 0, m = -1;
        for (auto &el : weights) h += el;
        int ans = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (canShip(weights, days, m)) {
                ans = m;
                h = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};