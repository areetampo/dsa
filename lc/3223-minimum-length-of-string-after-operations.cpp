class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        for (char& c : s) freq[c - 97]++;
        int res = 0;
        for (int &i : freq) res += i % 2 == 1 ? 1 : min(i, 2);//min cuz i can be 0
        return res;
    }
};