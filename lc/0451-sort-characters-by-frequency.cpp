class Solution {
public:
    string frequencySort(string s) {
        //using bucket sort
        unordered_map<char, int> freq;
        for (char &ch : s) ++freq[ch];
        vector<vector<string>> bucket(s.size() + 1);//if multiple chars with same freqs
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            char ch = it->first;
            int cnt = it->second;
            bucket[cnt].push_back(string(cnt, ch));
        }
        string res = "";
        for (int i = s.size(); i >= 0; --i) {
            for (string &S : bucket[i]) res += S;
        }
        return res;
    }
};