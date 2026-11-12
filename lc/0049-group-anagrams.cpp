class Solution {
public:
    string strSort(string s) {//copy passed
        vector<int> v(26, 0);
        for (char &ch : s) {
            ++v[ch - 'a'];
        }
        s = "";
        for (int i = 0; i < 26; ++i) {
            s += string(v[i], i - 'a');
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string &s : strs) {
            string key = strSort(s);
            m[key].push_back(s);//which strings form the same sorted sequence
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};