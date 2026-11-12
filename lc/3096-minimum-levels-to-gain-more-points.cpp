class Solution {
public:
    int minimumLevels(vector<int>& v) {
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            v[i] = v[i] ? 1 : -1;
            sum += v[i];
        }
        int l = v[0];//left sum
        sum -= v[0];
        if (l > sum) return 1;
        for (int i = 1; i < v.size() - 1; ++i) {//both player at least 1 level
            sum -= v[i];
            l += v[i];
            if (l > sum) return i + 1;
        }
        return -1;
    }
};