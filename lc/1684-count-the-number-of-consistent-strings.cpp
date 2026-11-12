class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> v(26, 0);
        for (char &c : allowed) v[c - 97] = 1;
        int cnt = 0;
        for (string &s : words) {
            int i = 0;
            while (i < s.size() && v[s[i] - 97]) i++;
            if (i == s.size()) cnt++;
        }
        return cnt;
    }
};