class Solution {
public:
    long long findMaximumScore(vector<int>& v) {
        int mx = 0, n = v.size(); long long res = 0;//mx is max el index
        //jump range * start of jump value so should focus on finding maximum element farthest from n - 1
        //eg 5,4,3,2,1 -> cal jump from 0 to n - 1 since 5 * range gives max output
        //jumping to 4 will give +5 then from 4 to 1 will give + 4 * 3 so its less, multiplying
        //maxximum range by 5 gives most output, so traverse from start and whenever max element changes, update
        //eg: 1,3,5,7,9
        //here, jumping at each next index is beneficial for max output
        //simple eg: 1,2,end -> jump 1 to end is res = 2, and jump 1 to 2 then 2 to end is res = 1 + 2
        //also if vals ==, then dont update since it would reduce the range
        for (int i = 1; i < n - 1; i++) {
            if (v[i] > v[mx]) {
                res += ((long long)i - mx) * v[mx];
                mx = i;
            }
        }
        return res + ((long long)n - 1 - mx) * v[mx];
    }
};