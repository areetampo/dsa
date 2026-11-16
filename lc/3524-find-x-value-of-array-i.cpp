class Solution {
public:
    /*
     * Why prefix products + modular inverse doesn't work:
     *  - Fermat's inverse power(b, k-2) needs k prime, so it fails for k = 4.
     *  - It also needs b to be coprime to k. Once a prefix product is 0 (mod k)
     *    (or 2 mod 4), it has no inverse, and P[j]/P[i] can't be recovered from
     *    the residues P[j]%k and P[i]%k alone. It would need restarts at multiples
     *    of k plus separate casework for k = 4.
     *
     * How this approach works (no division at all):
     *  - cnt[r] = number of subarrays ending at the previous index with product % k == r.
     *  - For a new element a, each such subarray extends to residue (r * a) % k,
     *    and the single-element subarray [a] starts at residue a % k.
     *  - Now cnt describes all subarrays ending at the current index, so add it to res.
     *  - Reducing mod k after every multiplication is always valid, so only k buckets
     *    are needed, not the real products. Time O(n * k), space O(k).
     */
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        vector<long long> cnt(k, 0);

        for (int a : nums) {
            vector<long long> next(k, 0);   // fresh array, don't update cnt in place
            next[a % k] += 1;               // start a new subarray [a]
            for (int r = 0; r < k; r++) {
                next[(r * (a % k)) % k] += cnt[r];  // extend old subarrays
            }
            cnt = next;
            for (int r = 0; r < k; r++) {
                res[r] += cnt[r];           // all subarrays ending at this index
            }
        }
        return res;
    }
};