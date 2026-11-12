class Solution {
public:
    void put_or_remove(int el, int* b, int oper) {
        int i = 0; el <<= 1;//can do since max is 1e9
        cout << el / 2 << endl;
        while (el) b[i++] += ((el >>= 1) & 1) * oper;
    }
    bool at_least_k(int* b, int k) {
        int el = 0;
        for (int i = 30; i >= 0; i--) {
            el = (el | !!b[i]) << 1;//!! means if b[i] >= 1 becomes 1 else stays 0
        }
        return el >> 1 >= k;
    }
    int minimumSubarrayLength(vector<int>& v, int k) {
        int b[31] = {0};
        int res = INT_MAX;
        for (int i = 0, j = 0; j < v.size(); j++) {
            put_or_remove(v[j], b, 1);
            while (at_least_k(b, k) && i <= j) {
                res = min(res, j - i + 1);
                put_or_remove(v[i], b, -1);
                i++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};