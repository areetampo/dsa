class Solution {
public:
    string findValidPair(string s) {
        vector<int> f(10, 0);
        for (char& c : s) f[c - '0']++;
        for (int i = 1; i < s.size(); i++) {
            char a = s[i - 1], b = s[i];
            // cout << a- '0' << " " << b -'0'<<"\n";
            if (a != b && f[a - '0'] == a - '0' && f[b - '0'] == b - '0')
            {
                string r= "";
                r += a; r += b;
                return r;
            }
        }
        return "";
    }
};