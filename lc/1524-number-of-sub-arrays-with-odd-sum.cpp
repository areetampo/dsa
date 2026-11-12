class Solution {
public:
    int numOfSubarrays(vector<int>& v) {
        int res = 0, MOD = 1e9 + 7;
        for (int i = 0, odd_sum = 0, even_sum = 1, sum_parity = 0; i < v.size(); i++) {
            sum_parity = (sum_parity + v[i]) % 2;
            res = (res + (sum_parity == 0 ? odd_sum : even_sum)) % MOD;
            even_sum += sum_parity == 0;
            odd_sum += sum_parity == 1;
            // cout << sum_parity << " " << even_sum << " " << odd_sum << "\n";
        }
        return res;
    }
};