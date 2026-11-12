class Solution {
public:
    unordered_map<int, unordered_map<string, int>> dp;
    int dfs(int i, vector<string>& words, vector<int>& letters, string& l, vector<int>& score) {
        if (i == words.size()) {
            return dp[i][l] = 0;
        }
        if (dp.find(i) != dp.end() && dp[i].find(l) != dp[i].end()) return dp[i][l];
        dp[i][l] = max(dp[i][l], dfs(i + 1, words, letters, l, score));
        int currWordScore = 0, enoughChars = 1;
        for (char c : words[i]) {
            currWordScore += score[c - 97];
            if (--letters[c - 97] < 0) {
                enoughChars = 0;
            }
        }
        string newL = "";
        if (enoughChars) {
            for (int x = 0; x < 26; x++) for (int y = 0; y < letters[x]; y++) newL += x + 97;
            dp[i][l] = max(dp[i][l], currWordScore + dfs(i + 1, words, letters, newL, score));
        }
        for (char c : words[i]) {
            letters[c - 97]++;
        }
        return dp[i][l];
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //max letters -> 100, max words -> 14
        //use dp[index][letters as string]
        dp.clear();
        vector<int> l(26, 0);
        for (auto c : letters) {
            l[c - 97]++;
        }
        string s = "";
        dfs(0, words, l, s, score);
        int res = 0;
        for (auto i = dp[0].begin(); i != dp[0].end(); i++) {
            res = max(res, i->second);
        }
        return res;
    }
};