class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        //sum of all local maximas - prev smaller element of mountain subarr
        // 1 2 3 4 3 5 4 -> res = 4 + 5 - 3 = 6
        // 0 0 0 0 0 0 0
        // 1 1 1 1 1 1 1
        // 1 2 2 2 2 2 2
        // 1 2 3 3 3 3 3
        // 1 2 3 4 3 4 4
        // 1 2 3 4 3 5 4 -> 6 steps
        //traverse increasing sequence left to right then after local maxima found
        //go left to right with the decreasing seq, now this whole mountain subarr
        //can be formed in local maxima number of steps
        //now the next eleemnt to the whole mountain sequence is greater than the
        //last element of the mountain seq so now again, start a new mountain
        //seq from it while also keeping track of last el of prev mountain seq
        //now each mountain seq can be formed by using peak of the that mountain
        //number of steps (peak value = selected subarrs who get +1 to their el)
        //eg: 1 2 3 2 1 made by 1 1 1 1 1 -> 1 2 2 2 1 -> 1 2 3 2 1
        //but if prev exists that means the base increments could come from prev
        //so subtract it, note that prev < curr mountain peak
        int prev = 0, n = v.size(), res = 0;
        for (int i = 0; i < n; i++) {
            while (i + 1 < n && v[i] <= v[i + 1]) i++;
            res += v[i] - prev;
            while (i + 1 < n && v[i] >= v[i + 1]) i++;
            prev = v[i];
        }
        return res;
    }
};