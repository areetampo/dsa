class Solution {
public:
    bool uniformArray(vector<int>& v) {
        // v[i] > v[j]
        // nums2[i] = v[i] - v[j]

        int n = v.size(), odds = count_if(v.begin(), v.end(), [&](int x){ return x & 1; });
        // all same parity already true
        if (odds == n || odds == 0) return 1;

        // odds > 0 
        // smallest odd cant become even since no odd smaller than it
        // hence all even array impossible

        // for all even array 
        // there needs to be atleast 1 odd smaller than smallest even
        
        int min_even = INT_MAX, min_odd = INT_MAX;

        for (int x : v)
            if (x & 1) min_odd = min(min_odd, x);
            else min_even = min(min_even, x);

        return min_odd < min_even;
    }
};