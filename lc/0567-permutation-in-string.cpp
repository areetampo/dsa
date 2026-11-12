class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return 0;
        vector<int> f(26, 0), k(26, 0);
        for (int i = 0; i < s1.length(); i++) f[s1[i] - 97]++, k[s2[i] - 97]++;
        for (int i = s1.length(); i < s2.length(); i++) {
            if (f == k) return 1;
            k[s2[i - s1.length()] - 97]--;
            k[s2[i] - 97]++;
        }
        return f == k;
    }
};