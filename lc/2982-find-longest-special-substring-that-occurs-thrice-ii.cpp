class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<string>> v(26);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n-1 && s[j] == s[j+1]) ++j;
            string ss = s.substr(i, j-i+1);
            v[ss[0] - 'a'].push_back(ss);
            i = j + 1;
        }
        
        int ans = -1;
        for (int x = 0; x < 26; ++x) { if (v[x].size() == 0) continue; vector<string> V = v[x];
            int i = 0;
            while (i < V.size()) {
                int j = i;
                while (j < V.size()-1 && V[j][0] == V[j+1][0]) ++j;
                unordered_map<int, int> m;//len, freq
                for (int k = i; k <= j; ++k) {
                    int len = (int)(V[k].length());
                    for (int z = 1; z <= len; ++z) {
                        m[z] += len-z+1;
                    }
                }
                for (auto it = m.begin(); it != m.end(); ++it) {
                    if (it->second >= 3) ans = max(ans, it->first);
                }
                i = j+1;   
            }
        }
        
        return ans;
    }
};