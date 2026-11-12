class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (char c : num) {
            while (k && res.size() && c < res.back()) {res.pop_back(); --k;}
            if (res == "" && c == '0') {}
            else res += c;
            // cout << res << " " << k << endl;
        }
        res = res.substr(0, res.length() - min((int)res.length(), k));
        return res.length() ? res : "0";
    }
};