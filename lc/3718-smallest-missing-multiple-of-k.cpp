class Solution {
public:
    int missingMultiple(vector<int>& v, int k) {
        int r = k;
        unordered_set<int> s(v.begin(), v.end());        
        while (s.find(r) != s.end())
            r += k;
        return r;
    }
};