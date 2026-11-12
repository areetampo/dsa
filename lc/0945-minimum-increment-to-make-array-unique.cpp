class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int> v(1e5 + 1, 0);//counting sort
        for (int &i : nums) v[i]++;
        int res = 0, mx = -1;
        // 1 1 2 2 3 7
        for (int i = 0; i <= 1e5; i++) {
            if (!v[i]) continue;
            //treating the val i as mx, eg: [1,1,1,2,2,2] -> 
            //1s incremented now mx is 3 -> [1,2,3,2,2,2] -> so turn all 2s to 4 at least by default [1,2,3,4,4,4]
            if (i <= mx) res += (mx - i + 1) * v[i];
            //now those v[i] - 1 number of 4s to be incremented to 5,6 ->
            res += v[i] == 3 ? 3 : v[i] * (v[i] - 1) / 2;//sum()
            //now looks like [1,2,3,4,5,6]
            //update mx to 6:
            //i <= mx -> all i's -> mx + 1 -> eg: 1,1,1,2,2 -> 1,2,3,2,2 so the last 2s must be 4s -> 1,2,3,4,4
            //mx = 3 -> becomes -> mx + 1 + v[i] - 1 = 4 + 1 = 5
            //i > mx -> do nothing -> eg: 1,1,1,7,7 -> 1,2,3,7,7 mx = 3 -> becomes -> i + v[i] - 1 = 8
            //note : v[i] - 1 is just to increment mx to the last occurence of the i th value
            mx = (i <= mx ? mx + 1 : i) + v[i] - 1;
            cout << i << " " << res << " " << mx << endl;
        }
        return res;
    }
};