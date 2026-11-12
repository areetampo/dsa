class Solution {
public:
    int sumOfGoodNumbers(vector<int>& v, int k) {
        int r = 0;
        for (int i = 0; i < v.size(); i++) {
            if (i - k < 0 && i + k >= v.size()) r += v[i];
            
            if (
                i - k >= 0 && v[i - k] < v[i] &&
                i + k < v.size() && v[i + k] < v[i]
                ) r += v[i];
            
            else if (
                i - k >= 0 && v[i - k] < v[i] &&
                i + k >= v.size()
                ) r += v[i];
            
            else if (
                i - k < 0 &&
                i + k < v.size() && v[i + k] < v[i]
                ) r += v[i];
            
        }
        return r;
    }
};