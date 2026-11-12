class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col = colsum.size();
        vector<vector<int>> res(2, vector<int> (col, 0));
        for (int i = 0; i < col; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
                --upper; --lower; 
                colsum[i] = 0;
            }
        }
        for (int i = 0; i < col; ++i) {
            if (colsum[i] == 2) return vector<vector<int>>();
            if (colsum[i]) {
                if (upper) {
                    res[0][i] = 1;
                    --upper;
                }
                else {
                    res[1][i] = 1;
                    --lower;
                }
            }
        }
        return (upper || lower) ? vector<vector<int>>() : res;
    }
};