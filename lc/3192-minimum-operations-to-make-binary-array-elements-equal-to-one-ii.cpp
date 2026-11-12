class Solution {
public:
    int minOperations(vector<int>& v) {
        int flips = 0, res = 0;
        for (int &i : v) {
            if (i == (flips % 2)) {
                flips++;
                res++;
            }
        }
        return res;
    }
};