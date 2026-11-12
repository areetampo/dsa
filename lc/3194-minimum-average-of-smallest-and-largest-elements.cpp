class Solution {
public:
    double minimumAverage(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        int i = 0, j = n - 1;
        double res = INT_MAX;
        while (i < j) {
            res = min(res, ((double)v[i] + v[j]) / 2);
            i++;
            j--;
        }
        return res;
    }
};