class Solution {
public:
    bool canBeValid(string s, string l) {
        int min = 0, max = 0;
        for (int i = 0; i < s.size(); i++) cout << (l[i] == '1' ? s[i] : '*');
        for (int i = 0; i < s.size(); i++) {
            if (l[i] == '1') {//locked
                if (s[i] == '(') {
                    min++;
                    max++;
                } else {
                    if (max == 0) return 0;
                    if (min > 0) --min;
                    --max;
                }
            } else {
                max++;
                if (min > 0) --min;
            }
            // cout << "\n" << min << " " << max;
        }
        return min == 0 && max % 2 == 0;
    }
};