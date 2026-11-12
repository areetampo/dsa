class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        int mx = INT_MIN;
        for (int &i : nums) {
            m[i]++;
            mx = max(mx, m[i]);
        }
        int res = 0;
        for (auto i = m.begin(); i != m.end(); ++i) {
            if (i->second == mx) res += mx;
        }
        return res;
    }
};