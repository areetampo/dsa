class Solution {
public:
    long long continuousSubarrays(vector<int>& v) {
        //max - min for any subarr <= 2 that is [0, 1, 2]
        //that means the subarr can have atmost 3 different values
        //2 pointers + size = 3 heap
        //so keep an ordered map (first key represents the min value)
        //move right pointer
        //move the left pointer until the total elements are > 3 as that would
        //never let the subarr have max - min <= 2 and the maximum and minimum
        //vals have differnce of <= 2
        //each new j element added and movement of i contribute to j - i + 1 new subarrs
        map<int, int> m;
        long long res = 0;
        for (int i = 0, j = 0; j < v.size(); j++) {
            m[v[j]]++;
            while (m.size() > 3 || m.rbegin()->first - m.begin()->first > 2) {
                if (--m[v[i]] == 0) m.erase(v[i]);
                i++; 
            }
            res += j - i + 1;
        }
        return res;
    }
};