class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& v) {
        int curr = 0; double res = 0;
        for (int i = 0; i < v.size(); i++) {
            res += v[i][1];
            if (curr <= v[i][0]) {
                curr = v[i][0] + v[i][1];
            } else {
                res += curr - v[i][0]; 
                curr += v[i][1];
            }
            // cout << curr << " " << res << endl;
        }
        return res / v.size();
    }
};