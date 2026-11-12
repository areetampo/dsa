class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26, 0);
        for (char& c : s) f[c - 97]++;
        vector<int> o, e;
        for (int i = 0; i < 26; i++) {
            if (f[i] == 0) continue;
            if (f[i] % 2 == 0) {
                e.push_back(f[i]);
            } else {
                o.push_back(f[i]);
            }
        }
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());
        //maximize o - e
        // for (int & i : o) cout << i << " "; cout << endl;
        // for (int & i : e) cout << i << " "; cout << endl;
        return o.back() - e.front();
    }
};