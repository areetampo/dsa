class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size(), res_idx = 0, v_idx = 0, skip = 0;
        vector<int> res(n, 0);//input doesnt contain 0
        while (v_idx < n) {
            if (skip == 1 && res[res_idx] == 0) {
                skip = 0;
            } else if (skip == 0 && res[res_idx] == 0)  {
                res[res_idx] = v[v_idx++];
                skip = 1;
            }
            res_idx = (res_idx + 1) % n;
        }
        return res;
    }
};