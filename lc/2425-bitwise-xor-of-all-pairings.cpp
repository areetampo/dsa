class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int &i : nums1) res ^= i * (nums2.size() % 2);
        for (int &i : nums2) res ^= i * (nums1.size() % 2);
        return res;
    }
};