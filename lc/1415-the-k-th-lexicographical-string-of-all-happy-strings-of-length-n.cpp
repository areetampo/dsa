class Solution {
public:
    string getHappyString(int n, int k) {
        int m = 1 << (n - 1);
        if (k > 3 * m) return "";
        string r = "a";
        if (m < k && k <= 2 * m) r.back() = 'b';
        if (k > 2 * m) r.back() = 'c';
        k -= (r.back() - 'a') * m; 
        m >>= 1;
        while (m) {
            // cout << k << " " << m << " " << r << "\n";
            if (k > m) {
                r += r.back() == 'c' ? 'b' : 'c';
                k -= 1 * m;
            } else {
                r += r.back() == 'a' ? 'b' : 'a';
                k -= 0 * m;
            }
            m >>= 1;
        }
        // cout << k << " " << m << " " << r << "\n";
        return r;
    }
};