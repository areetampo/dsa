class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int r = 0;

        for (int i = 0, j = 0; j < nums.size(); j++) {
            while (m[nums[j]] == k)
                m[nums[i++]]--;
            m[nums[j]]++;
            r = max(r, j - i + 1);
        }
        
        return r;
    }
};