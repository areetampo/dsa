class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        vector<vector<int>> v(26);
        for (int i = 0; i < s.size(); i++) {
            int req = 25 - (s[i] - 97);
            // cout << s[i] << " " << (char)(req + 97) << " " << v[req].size() << "\n";
            if (v[req].empty()) v[s[i] - 97].push_back(i);
            else {
                res += i - v[req].back();
                v[req].pop_back();
            }
        }
        return res;
    }
};