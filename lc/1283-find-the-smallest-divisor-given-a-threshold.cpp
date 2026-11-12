class Solution {
private: 
    bool divResult(const vector<int> &nums, int threshold, int divisor) {
        long long curr = 0;
        for (auto &el : nums) {
            curr += el/divisor + ((el % divisor) ? 1 : 0);
            if (curr > threshold) return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //koko eating bananas
        //threshold = hours, divisor = k bananas
        int mx = INT_MIN;
        for (auto &el : nums) mx = max(mx, el);
        int l = 1, h = mx, m = -1;
        int ans = -1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (divResult(nums, threshold, m)) {
                ans = m;
                h = m - 1;
            }
            else l = m + 1;
        }
        return l;
    }
};