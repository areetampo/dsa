class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> v(26, 0);//freq
        for (char &ch : s) ++v[ch - 97];
        vector<int> v1(26, 0);//auxi
        while (1) {
            for (int i = 0; i < 26; ++i) v1[i] = v[i];
            int mx = 0;
            for (int i = 0; i < 26; ++i) {
                if (v[i]) --v[i];
                mx = max(mx, v[i]);
            }
            if (!mx) break;
        }
        //now in v1 if freq exist (will be 1/0) then that char in last operation string
        vector<pair<int, char>> v2(26);//store final occurence of each char in s
        for (int i = 0; i < 26; ++i) {
            v2[i] = {INT_MAX, i};//occurence idx, the char
        }
        for (int i = 0; i < s.length(); ++i) v2[s[i] - 97].first = i;
        sort(v2.begin(), v2.end());
        unordered_set<int> ss;//use set of O(1) lookup for each char last occurence
        for (auto& i : v2) ss.insert(i.first);
        string res = "";
        for (int i = 0; i < s.length(); ++i) {
            if (ss.find(i) != ss.end() && v1[s[i] - 97]) {//if the char's index is counted in (present in map)
                res += s[i];
            }
        }
        return res;
    }
};