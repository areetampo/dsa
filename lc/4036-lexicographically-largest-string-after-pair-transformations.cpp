class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        // 2^0 = a
        // 2^1 = b
        // 2^2 = c
        // 2^25 = z
        vector<string> r;
        for (int i : nums) {
            string s = "";
            for (int j = 25; j >= 0; j--) {
                if ((1 << j) <= i) {
                    int cnt = i / (1 << j);
                    s += string(cnt, char(j + 97));
                    i -= cnt * (1 << j);
                }
            }
            r.push_back(s);
        }
        return r;
    }
};