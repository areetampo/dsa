class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums) m[i]++;
        int res = 0;
        for (auto i = m.begin(); i != m.end(); ++i) {
            if (i->second == 2) res ^= i->first;
        }
        return res;
    }
};