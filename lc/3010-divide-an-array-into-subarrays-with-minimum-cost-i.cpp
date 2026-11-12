class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(nums);
        v[0] = INT_MAX;
        sort(v.begin(), v.end());
        // int a = max(max(v[0][0], v[1][0]), v[2][0]);
        // int c = min(min(v[0][0], v[1][0]), v[2][0]);
        // int b = -1;
        // if (a == v[0][0]) {
        //     if (c == v[1][0]) b = v[2][0];
        //     else b = v[1][0];
        // }
        // else if (a == v[1][0]) {
        //     if (c == v[0][0]) b = v[2][0];
        //     else b = v[0][0];
        // }
        // else {
        //     if (c == v[1][0]) b = v[0][0];
        //     else b = v[1][0];
        // }
        int i = n-1, res = 0;
//         while (i >= 0) {
//             int mn = INT_MAX;
            
//         }
        res += nums[0] + v[0] + v[1];
        return res;
    }
};