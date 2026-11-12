class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int &i : nums) ++m[i];
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 1) return -1;
            res += it->second / 3 + ((it->second % 3) ? 1 : 0); 
        }
        return res;
    }
};