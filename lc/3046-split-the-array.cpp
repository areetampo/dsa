class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& i : nums) {
            ++m[i];
            if (m[i] > 2) return 0;
        }
        return 1;
    }
};