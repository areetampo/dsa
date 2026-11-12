class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> res;
        for (int i = l; i <= r; i++) {
            int num = i;
            while (num != 0) {
                int last = num % 10;
                if (last == 0 || i % last != 0) {
                    break;
                }
                num /= 10;
            }
            if (num == 0) res.push_back(i);
        }
        return res;
    }
};