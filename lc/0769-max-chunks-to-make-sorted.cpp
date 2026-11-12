class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int res = 0;
        for (int i = 0, mx = -1; i < v.size(); i++) 
            if ((mx = max(mx, v[i])) == i) res++;
        return res;
    }
};