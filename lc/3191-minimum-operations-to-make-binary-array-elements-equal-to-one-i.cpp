class Solution {
public:
    int minOperations(vector<int>& a, int k = 3) {
        int res = 0;
        for (int i = 0, flips = 0; i < a.size(); i++) {
            if (a[i] >= 2) {
                flips--, a[i] &= 1;
            }
            if ((a[i] + flips) % 2 == 0) {
                if (i > a.size() - k) return -1;
                res++, flips++;
                if (i + k < a.size()) a[i + k] |= 2;
            }
        }
        return res;
        
    }
};