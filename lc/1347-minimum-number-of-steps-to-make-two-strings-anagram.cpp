class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26, 0);
        for (char &ch : s) {
            v[ch - 'a']++;
        }
        for (char &ch : t) {
            v[ch - 'a']--;
        }
        int res = 0;
        for (int &i : v) {
            if (i > 0) res += i;
        }
        return res;
    }
};