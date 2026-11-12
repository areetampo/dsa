class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> res(n); int seen[51] = {0};
        seen[a[0]]++, seen[b[0]]++;
        res[0] = seen[a[0]] == 2;
        for (int i = 1; i < a.size(); i++) {
            res[i] = res[i - 1] + (++seen[a[i]] == 2) + (++seen[b[i]] == 2);
        }
        return res;
    }
};