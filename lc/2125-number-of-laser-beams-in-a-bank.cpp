class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev1 = 0, curr1 = 0, res = 0;
        for (auto &s : bank) {
            for (auto &ch : s) {
                if (ch == '1') ++curr1;
            }
            res += curr1 * prev1;
            if (curr1) prev1 = curr1;
            curr1 = 0;
        }
        return res;
    }
};