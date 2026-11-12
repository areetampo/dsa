class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int &i : nums) {
            sum += i;
            if (!sum) ++res;
        }
        return res;
    }
};