class Solution {
public:
    long long maxSubarraySum(vector<int>& v, int k) {
        //mark each idx % k with minimum presum
        //at each index, the max sum subarr to its left starting from it can be
        //found by presum[i] - m[i % k], m[i % k] is all the prev indices such that
        //[i % k .... i] subarr size % k == 0 so curr sum (presum[i]) - minimum
        //value from those indices' presum gives current max subarr sum for a subarr
        //whose size % k == 0, also keep storing the min presum for current idx % k
        long long curr = 0;
        vector<long long> m(k, 1e18);
        //before arr (at -1 idx) mark = 0
        m[((-1 % k) + k) % k] = 0;
        for (int i = 0; i < k; i++) {//init
            curr += v[i];
            m[i % k] = min(m[i % k], curr);
        }
        long long res = curr;
        for (int i = k; i < v.size(); i++) {
            curr += v[i];
            res = max(res, curr - m[i % k]);
            m[i % k] = min(m[i % k], curr);
        }
        return res;
    }
};