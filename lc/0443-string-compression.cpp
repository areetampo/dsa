class Solution {
public:
    int compress(vector<char>& chars) {
        int w = 0, n = chars.size(), cnt = 0;
        if (n == 1) return 1;
        for (int r = 0; r < n - 1; r++) {
            cnt++;
            if (chars[r] != chars[r + 1]) {
                chars[w++] = chars[r];
                if (cnt > 1) {
                    int k = pow(10, (int)log10(cnt));
                    while (k > 0) {
                        chars[w] = ((cnt / k) % 10) + '0';
                        k /= 10, w++;
                    }
                }
                cnt = 0;
            }
        }
        if (chars[n - 2] == chars[n - 1]) {
            cnt++;
            chars[w++] = chars[n - 1];
            if (cnt > 1) {
                int k = pow(10, (int)log10(cnt));
                while (k > 0) {
                    chars[w] = ((cnt / k) % 10) + '0';
                    k /= 10, w++;
                }
            }
        } else chars[w++] = chars[n - 1];
        for (char& c : chars) cout << c << " ";
        return w;
    }
};