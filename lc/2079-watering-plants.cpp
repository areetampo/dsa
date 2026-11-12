class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        int res = 0, C = c;
        for (int i = 0; i < p.size(); ++i) {
            if (c >= p[i]) {
                ++res;
                c -= p[i];
            }
            else {
                res += i;
                c = C;
                res += i+1;
                c -= p[i];
            }
        }
        return res;
    }
};