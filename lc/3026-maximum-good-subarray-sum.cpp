class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        vector<long long> p(n, 0);//prefix sum
        long long s = 0;
        for (int i = 0; i < n; ++i) {
            p[i] = s += v[i];
        }
        long long res = LONG_LONG_MIN;
        int exists = 0;//to check if a good subarray exists: abs(last el - first el) = k
        unordered_map<long long, int> m;
        for (int i = 0; i < n; ++i) {
            int a = v[i];
            long long x = a - k, y = a + k;//to check if a value exists whose difference with our curr value is k
            if (m.find(x) != m.end()) {
                res = max(res, p[i] - p[m[x]] + x);
                exists = 1;
            }
            if (m.find(y) != m.end()) {
                res = max(res, p[i] - p[m[y]] + y);
                exists = 1;
            }
            //we should only keep 1 index for all values in our map, if the value we are currently on is already 
            //present in map, how to decide if we should change to new index or let it stay the previous index?
            //eg arr: 3 0 -1 3 1 2, k = 1
            //idx:    0 1  2 3 4 5
            //suppose we are at index 3 and the value is also 3 and we encounter that 3 is already in map (index 0)
            //now if we keep it that way, the next time we are calculating our good subarray sum, it will be
            //counted from that index but if we change the index to 3 that means we will be neglecting the sum of 
            //index 0,1,2 here. As we require the max sum of good subarray we can check if keeping the previous index
            //i.e. the sum of idx 0,1,2 is beneficial or we can jsut scrape it off and update our index for value 3
            //to be idx 3 that means we check if the sum of index 0,1,2 is positive (it contributes to maximize
            //sum of our good subarray in future) then we don't update the index in our map otherwise we do
            if (m.find(a) == m.end() || 0 > p[i] - p[m[a]]) m[a] = i;
        }
        return (exists) ? res : 0;
    }
};