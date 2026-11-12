class Solution {
public:
    string smallestNumber(string s) {
        int x = 1;
        string r;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == 'I') {
                r += x++ + '0';
                i++;
            } else {
                int j = i;
                while (j < s.size() && s[j] == 'D') j++;
                int len = j - i;
                x += len;
                for (int k = i; k <= j; k++) {
                    r += x-- + '0';
                }
                x += len + 2;
                i = j + 1;
            }
            // cout << r << ", x " << x << ", i " << i << "\n";
        }
        if (s.back() == 'I') r += x + '0';
        return r;
    }
};