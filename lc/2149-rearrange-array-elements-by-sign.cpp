class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positiveIdx = 0, negativeIdx = 1;
        vector<int> ans(nums.size(), 0);
        for (int &i : nums) {
            if (i > 0) {
                ans[positiveIdx] = i;
                positiveIdx += 2;
            }
            else {
                ans[negativeIdx] = i;
                negativeIdx += 2;
            }
        }
        return ans;
    }
};