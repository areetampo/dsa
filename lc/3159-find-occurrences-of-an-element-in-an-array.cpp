class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        vector<int> o;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) o.push_back(i);
        }
        vector<int> res;
        for (int i : q) {
            res.push_back(i <= o.size() ? o[i - 1] : -1);
        }
        return res;
    }
};