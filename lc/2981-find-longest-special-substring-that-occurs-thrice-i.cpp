class Solution {
public:
    int maximumLength(string s) {
        //for each char, note the top 3 longest special sequences
        vector<vector<int>> v(26);
        for (int i = 0, j; i < s.size(); i = j + 1) {
            j = i;
            while (j + 1 < s.size() && s[j] == s[j + 1]) j++;
            int len = j - i + 1;
            char ch = s[j];
            v[ch - 97].push_back(len);
        }
        for (auto &i : v) sort(i.rbegin(), i.rend());
        int res = -1;
        for (auto &i : v) {
            int sz = i.size(), r = -1;
            if (sz == 1 && i[0] >= 3) r = i[0] - 2;
            if (sz >= 2) {
                if (i[0] >= i[1] + 2) r = i[0] - 2;
                else if (i[0] == i[1] + 1) r = i[1];
                else if (sz == 2 && i[0] > 1) r = i[0] - 1;
                //i[0] == i[1] >= i[2]
                else if (sz >= 3) {
                    if (i[1] == i[2]) r = i[0];//all 3 equal
                    else r = i[0] - 1;//i[0] = i[1] > i[2]
                } 
            }
            res = max(res, r);
        }
        return res;
    }
};