class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long >> v(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < original.size(); i++) {
            v[original[i] - 97][changed[i] - 97] = min(v[original[i] - 97][changed[i] - 97], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (v[i][k] != LLONG_MAX && v[k][j] != LLONG_MAX) {
                        v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
                    }
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < source.length(); i++) {
            char s = source[i], t = target[i];
            if (s != t && v[s - 97][t - 97] == LLONG_MAX) return -1;
            if (s != t) res += v[s - 97][t - 97];
        }
        return res;
    }
};