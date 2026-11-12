class Solution {
public:
    string vw = "aeiou";
long long countAtLeastK(string &w, int k) {
    long long res = 0, j = 0, cnt[6] = {}, unique = 0;
    for (int i = 0; i < w.size(); ++i) {
        int p = vw.find(w[i]) + 1;
        unique += ++cnt[p] == 1 && p;
        while (unique == 5 && cnt[0] >= k) {
            res += w.size() - i;
            int p = vw.find(w[j++]) + 1;
            unique -= --cnt[p] == 0 && p;                
        }
    }
    return res;
}
long long countOfSubstrings(string w, int k) {
    return countAtLeastK(w, k) - countAtLeastK(w, k + 1);
}
};