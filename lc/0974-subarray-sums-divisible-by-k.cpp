class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;//presum % k, num of appearances
        int res = 0;//total subarrays
        m[0] = 1;//eg: [5], k = 5, so presum[0] = 5, presum[0] % k == 0 -> req subarr so sum till 0th idx div by k
        int presum = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int modulo = ((presum % k) + k) % k;//(x + k) % k to ensure -ve's modulo computed correctly
            if (m.find(modulo) != m.end()) {
                res += m[modulo];
            }
            m[modulo]++;
        }
        return res;
    }
};