class Solution {
public:
    int maxDistance(string str, int k) {
        int r = 0, n = 0, s = 0, e = 0, w = 0;
        for (char &c : str) {
            n += c == 'N';
            s += c == 'S';
            e += c == 'E';
            w += c == 'W';
            int x = min(n, s), y = min(e, w),
                inc_with_k = 2 * min(k, x + y);
            r = max(r, abs(n - s) + abs(e - w) + inc_with_k);
        }
        return r;
    }
};