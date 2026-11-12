class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int o = 0, e = 0;
        for (int& i : nums) {
            o += i % 2 == 1;
            e += i % 2 == 0;
        }
        vector<int> res;
        for (int i = 0; i < e; i++) res.push_back(0);
        for (int i = 0; i < o; i++) res.push_back(1);
        return res;
    }
};