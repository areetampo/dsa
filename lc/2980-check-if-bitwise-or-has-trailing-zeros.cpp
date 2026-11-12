class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        bool c1 = false, c2 = false;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0 && !c1) c1 = true;
            else if (nums[i] % 2 == 0 && !c2) c2 = true;
            if (c1 && c2) return true;
        }
        return false;
    }
};