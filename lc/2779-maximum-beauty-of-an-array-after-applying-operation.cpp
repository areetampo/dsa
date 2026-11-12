class Solution {
public:
    int maximumBeauty(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0, j = 0; j < v.size(); ) {
            if (v[j] - v[i] <= 2 * k) {
                res = max(res, j - i + 1);
                j++;
            }
            else i++;
        }
        return res;
    }
};