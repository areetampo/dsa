class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        sort(p.begin(), p.end());
        int s = 0, e = p.size() - 1;
        int res = 0;
        while (s <= e) {
            if (p[s] + p[e] <= l) {
                s++; e--;
            } else {
                e--;
            }
            ++res;
        }
        return res;
    }
};