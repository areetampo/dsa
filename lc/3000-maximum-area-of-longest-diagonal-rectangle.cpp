class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& m) {
        int res = 0; double d = 0;
        for (int i = 0; i < m.size(); ++i) {
            
            double x = (double)m[i][0] * (double)m[i][0];
            double y = (double)m[i][1] * (double)m[i][1];
            
            if (x + y > d) {
                d = x + y;
                res = m[i][0] * m[i][1];
            }
            else if (x + y == d) res = max(res, m[i][0] * m[i][1]);
            
        }
        return res;
    }
};