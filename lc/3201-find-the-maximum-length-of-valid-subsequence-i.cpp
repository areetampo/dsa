class Solution {
public:
    int maximumLength(vector<int>& v) {
        int o = 0, e = 0, oe = 0, eo = 0;
        for (int &i : v) {
            if (i % 2) o++;
            else e++;
        }
        int i = 0;
        if (v[i] % 2) {
            int p = 1;
            while (i < v.size()) {
                if (p == v[i] % 2) {
                    oe++;
                    p = (p + 1) % 2;
                }
                i++;
            }
        } else {
            int p = 0;
            while (i < v.size()) {
                if (p == v[i] % 2) {
                    eo++;
                    p = (p + 1) % 2;
                }
                i++;
            }
        }
        return max(max(o, e), max(oe, eo));
        
    }
};