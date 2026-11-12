class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> global(26, 1000);
        for (string &w : words) {
            vector<int> local(26, 0);
            for (char &c : w) {
                local[c - 97]++;
            }
            for (int i = 0; i < 26; i++) global[i] = min(global[i], local[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) 
            for (int j = 0; j < global[i]; j++) 
                res.push_back(string(1, i + 97));
        return res;
    }
};