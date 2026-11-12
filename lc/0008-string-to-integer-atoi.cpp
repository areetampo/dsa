class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int i = 0, minus = 0, plus = 0, nums = 0;
        while (i < s.length() && s[i] == ' ') { ++i; }
        while (i < s.length()) {
            char ch = s[i];
            if (ch != '+' && ch != '-' && (ch < '0' || '9' < ch)) { cout << 1 << endl; break; }
            if (ch == '-' || ch == '+') {
                if (minus || plus || nums) break;
                if (ch == '-') minus = 1;
                else plus = 1;
            }
            else {//ch is a digit
                if (res > INT_MAX / 10) return (minus) ? INT_MIN : INT_MAX;
                if (res == INT_MAX / 10) {
                    if (minus) {
                        if (ch - '0' >= 8) return INT_MIN;
                    } else if (ch - '0' >= 7) return INT_MAX;
                }
                if (log10(res) == 9) {//10 digit already and about to add another digit
                    return (minus) ? INT_MIN : INT_MAX;
                }
                ++nums;
                res = res * 10 + (ch - '0');
            }
            ++i;
        }
        // cout << i << " " << res << endl;
        return (minus) ? -res : res;
    }
};
// "  -112a    42"
// "    +0a32"
// "   +0 123"
// "  +  413"
// "  - 1"
// "--1"
// "00000-42a1234"
// "-2147483648"