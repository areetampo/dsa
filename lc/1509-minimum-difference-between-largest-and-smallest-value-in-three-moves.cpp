class Solution {
public:
    int minDifference(vector<int>& v) {
        int n = v.size();
        if (n < 5) return 0;
        sort(v.begin(), v.end());
        return min(min(v[n - 4] - v[0], v[n - 3] - v[1]), min(v[n - 2] - v[2], v[n - 1] - v[3]));        
    }
};