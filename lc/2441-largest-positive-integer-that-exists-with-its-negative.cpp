class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s;
        int res = -1;
        for (int i : nums) {
            if (s.find(-i) != s.end()) res = max(res, abs(i));
            s.insert(i);
        }
        return res;
    }
};