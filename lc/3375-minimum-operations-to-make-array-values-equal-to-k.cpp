class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for (int &i : nums) if (i < k) return -1;
        unordered_map<int, int> m;
        for (int &i : nums) m[i]++;
        return m.size() - (m.find(k) != m.end());
    }
};