class Solution {
public:
    bool canConstruct(string s, int k) {
        int freq[26] = {0};
        for (char &c : s) freq[c - 97]++;
        int odd = 0;
        for (auto i = begin(freq); i < end(freq); i++) 
            odd += *i % 2;
        return s.size() >= k && odd <= k;
    }
};