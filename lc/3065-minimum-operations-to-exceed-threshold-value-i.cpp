class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int& i : nums) if (i < k) ++res;
        return res;
    }
};