class Solution {
public:
    int minimumOperations(vector<int>& v) {
        int res = 0;
        for (int &i : v) {
            res += i % 3 != 0;
        }
        return res;
    }
};