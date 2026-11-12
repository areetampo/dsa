class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long oper = 0;
        int curr_k = k, mod = 1e9 + 7;
        for (int &i : nums) {
            curr_k -= i;
            if (curr_k < 0) {
                long long oper_todo = -curr_k / k + (-curr_k % k ? 1 : 0);
                curr_k += oper_todo * k;
                oper = (oper + oper_todo) % mod;
            }
        }
        return (oper * (oper + 1) / 2) % mod;
    }
};