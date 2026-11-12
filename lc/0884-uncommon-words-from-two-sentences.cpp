class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 += " " + s2;
        unordered_map<string, int> s;
        for (int i = 0; i < s1.size(); ) {
            int j = i;
            string S = "";
            while (j < s1.size() && s1[j] != ' ') S += s1[j++];
            i = j + 1;
            s[S]++;
        }
        vector<string> res;
        for (auto i : s) if (i.second == 1) res.push_back(i.first);
        return res;
    }
};