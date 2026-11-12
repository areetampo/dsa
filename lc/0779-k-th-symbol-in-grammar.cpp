class Solution {
public:
    //tree like structure:
    //                     0
    //                 /       \
    //             0               1
    //           /   \           /   \
    //         0       1       1       0
    //        / \     / \     / \     / \
    //       0   1   1   0   1   0   0   1
    //       |   |   |   |   |   |   |   |
    //      0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
    //         L
    // 0110100110010110 n = 5 k = 9
    //     L
    // 01101001
    // L
    // 0110
    // R
    // 01
    // 0
    int kthGrammar(int n, int k) {
        int len = 1 << (n - 1);//len of last seq is 1 << (n - 1);
        vector<int> v;
        while (len > 1) {//len = 1 means 0 is the val
            //move left (0) or right (1) of 0 -> 01: left is move to 0 and right
            //is move to 1 | 1 -> 10: left is move to 1 and right is move to 0
            v.push_back(k % 2 == 0);
            k = (k + 1) / 2;
            len /= 2;
        }
        for (int &i : v) cout << (i == 0 ? 'L' : 'R') << " ";
        int res = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i]) {
                res = res == 0 ? 1 : 0;
            } else {
                res = res == 0 ? 0 : 1;
            }
        }
        return res;
    }
};