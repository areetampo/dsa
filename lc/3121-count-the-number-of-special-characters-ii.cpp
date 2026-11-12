class Solution {
public:
    int numberOfSpecialChars(string s) {
        vector<int> v(26, 0);
        for (char c : s) {
            if (c > 96) {
                int i = c - 97;
                if (v[i] == 0) {
                    v[i] = 1;
                } else if (v[i] == 2) {
                    v[i] = -1;
                }
            } else {
                int i = c - 65;
                if (v[i] == 0) v[i] = -1;
                else if (v[i] == 1) v[i] = 2;
            }
        }
        int res = 0;
        for (int i : v) if (i == 2) ++res;
        return res;
    }
};