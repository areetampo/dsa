class Solution {
public:
    bool isNStraightHand(vector<int>& v, int sz) {
        map<int, int> m;
        for (int &i : v) m[i]++;
        // int groups = 0;
        for (auto i = m.begin(); i != m.end(); i++) {
            int val = i->first, freq = i->second;
            // cout << val << " " << freq << endl;
            if (!freq) continue;
            for (int j = 0; j < sz; j++) {
                if ((m[val + j] -= freq) < 0) return 0;
            }
            // groups += freq;
        }
        return 1;
    }
};