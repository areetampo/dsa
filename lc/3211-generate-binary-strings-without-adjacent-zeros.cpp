class Solution {
public:
    void f(string s, int i, vector<string>& res) {
        if (i == 0) {
            res.push_back(s);
            return;
        }
        string t(s);
        f(t + "1", i - 1, res);
        if (s[s.size() - 1] == '1') {
            f(s + "0", i - 1, res);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        f("1", n - 1, res);
        f("0", n - 1, res);
        return res;
    }
};