class Solution {
public:
    int minSubarray(vector<int>& v, int p) {
        //(v sum - subarr sum) % p == 0
        //v sum % p == subarr sum % p
        int r = accumulate(v.begin(), v.end(), 0, [p](int acc, int a){
            return (((acc + a) % p) + p) % p;
        });
        unordered_map<int, int> m = {{0, -1}};//presum % p, latest index (need min len subarr)
        //the subarr % p should be == r
        int presum = 0, res = 1e9;
        //[a b c d ..... e f g h]
        //        |_______| ----> res subarr whose sum % p == r, map will have ->
        //a remainder value [0, p) for each index and same remainder key will have the latest index as value
        //cuz minimum len req as res
        //let sum till d % p == k1, sum till e % p = k2
        //if the gap in k1 and k2 == r which means the sum till d and sum till e has diff == k*p + r
        for (int i = 0; i < v.size(); i++) {
            presum = (((presum + v[i]) % p) + p) % p;
            m[presum] = i;//latest index for each remainder
            int req = (presum - r + p) % p;//+p cuz can be -ve
            if (m.count(req)) res = min(res, i - m[req]);
            // m[presum] = i;//latest index for each remainder
        } 
        // int req = (presum - r + p) % p;//+p cuz can be -ve
        // if (m.count(req)) res = min(res, (int)v.size() - 1 - m[req]); --> for the last idx put into map
        //so just shift m[presum] = i statement top so executed for last element as well in loop only
        
        return res == (int)v.size() ? -1 : res;//non empty arr
    }
};