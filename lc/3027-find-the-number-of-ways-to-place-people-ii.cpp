class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b){
            return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
        });
        int res = 0;
        for (int i = 0; i < p.size() - 1; ++i) {
            for (int j = i + 1, y = INT_MIN; j < p.size(); ++j)
            if (p[i][1] >= p[j][1] && y < p[j][1]) {
                ++res;
                y = p[j][1];
            }
        }
        return res;
    }
};