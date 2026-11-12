class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        map<int, vector<int>> m;
        vector<int> v;
 
        for (int i = 0; i < nums.size() / 2; ++i) {
            int a = nums[i];
            int b = nums[nums.size() - i - 1];
            int diff = abs(a - b);

             int X = max({a, b, k - a, k - b});

             m[diff].push_back(X);
            v.push_back(X);
        }

        int ans = nums.size();  
        sort(v.begin(), v.end());

        for (const auto& [diff, values] : m) {
            int T = lower_bound(v.begin(), v.end(), diff) - v.begin();
            T = T * 2 + (nums.size() / 2 - T);

            for (const auto& X : values) {
                if (X < diff) {
                    T -= 2;
                } else {
                    T -= 1;
                }
            }

            ans = min(ans, T);
        }

        return ans;
    }

};