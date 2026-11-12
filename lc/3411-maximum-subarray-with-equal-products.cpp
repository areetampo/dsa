class Solution {
public:
    int maxLength(vector<int>& v) {
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            unsigned long long p = 1, g = v[i], l = v[i];
            for (int j = i; j < v.size(); j++) {
                p *= v[j];
                // if (p > 900) break;
                l = lcm(l, v[j]);
                g = gcd(g, v[j]);
                if (p == l * g) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};