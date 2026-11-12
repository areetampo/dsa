class Solution {
public:
    char findKthBit(int n, int k) {
        int rev = 0;
        int len = pow(2, n) - 1;
        for (int i = 1; i < n; i++) {
            int mid = len / 2 + 1;
            cout << len << " " << mid << " " << k << " " << rev << endl;
            //mid always 1 so return 1 if even revarsals
            if (k == mid) return (rev % 2 == 0 ? 1 : 0) + '0';
            if (k > mid) {
                k = len - k + 1;
                rev++;
            }
            len /= 2;
        };
        return (rev % 2 == 0 ? 0 : 1) + '0';//return 0 if even reversals
    }
};