class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin(), rs.end());
        int r = 0, taken_row = 0;
        for (int i = 0; i < rs.size(); i++, taken_row++) {
            bool _rs[11] = {0};
            fill(_rs, _rs + 11, 0);
            _rs[rs[i][1]] = 1;
            while (i + 1 < rs.size() && rs[i][0] == rs[i + 1][0]) {
                _rs[rs[i + 1][1]] = 1;
                i++;
            }
            bool a = all_of(_rs + 2, _rs + 6, [](bool x){ return x == 0; }),
                b = all_of(_rs + 4, _rs + 8, [](bool x){ return x == 0; }),
                c = all_of(_rs + 6, _rs + 10, [](bool x){ return x == 0; });
            r += a && c ? 2 : a || b || c;
        }
        return r + (n - taken_row) * 2;
    }
};