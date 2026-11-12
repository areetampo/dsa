class Solution {
public:
    void place(vector<int> &v, int x) {
        int lo = 0, hi = v.size() - 1, m = -1;
        while (lo <= hi) {
            m = (lo + hi) >> 1;
            if (v[m] >= x) hi = m - 1;
            else lo = m + 1;
        }
        v[lo] = x;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub = { nums[0] };
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > sub[sub.size() - 1]) sub.push_back(nums[i]);
            if (nums[i] < sub[sub.size() - 1]) place(sub, nums[i]);
        }
        return sub.size();
    }
};