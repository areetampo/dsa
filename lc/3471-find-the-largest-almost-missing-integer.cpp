class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == k) return *max_element(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int& i : nums) m[i]++;
        if (k == 1) {
            int mx = -1;
            for (auto& [k, v] : m)
                if (v == 1) mx = max(mx, k);
            return mx;
        }
        int a = nums[0], b = nums[n - 1];
        if (m[a] > 1 && m[b] > 1) return -1;
        if (m[a] > 1) return b;
        if (m[b] > 1) return a;
        return max(a, b);
    }
};