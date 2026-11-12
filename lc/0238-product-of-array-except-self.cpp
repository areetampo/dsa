class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        int zeros = count(v.begin(), v.end(), 0);
        if (zeros > 1) return vector<int>(n, 0);
        if (zeros == 1) {
            int prod = 1, i;
            for (int j = 0; j < n; j++) {
                if (v[j] == 0) i = j;
                else prod *= v[j];
            }
            vector<int> res(n, 0);
            res[i] = prod;
            return res;
        }
        vector<int> res(n, 1);
        for (int i = 0, left = 1; i < n; left *= v[i], i++) {
            res[i] = left;
        }
        for (int i = n - 1, right = 1; i >= 0; right *= v[i], i--) {
            res[i] *= right;
        }
        return res;
    }
};