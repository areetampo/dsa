class Solution {
public:
    bool isArraySpecial(vector<int>& v) {
        for (int i = 1; i < v.size(); i++) if ((v[i - 1] + v[i]) % 2 == 0) return 0;
        return 1;
    }
};