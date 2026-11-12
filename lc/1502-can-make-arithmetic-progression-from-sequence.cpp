class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& v) {
        sort(v.begin(), v.end());
        for (int i = 2; i < v.size(); i++) {
            if (v[i- 2] - v[i - 1] != v[i-1] - v[i]) return false;
        }
        return true;
    }
};