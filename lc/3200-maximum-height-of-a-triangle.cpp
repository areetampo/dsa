class Solution {
public:
    int maxHeightOfTriangle(int r, int b) {
        int res = 0;
        int R = r, B = b;
        for (int i = 1; ; i++) {
            if (i % 2 && R - i < 0 || i % 2 == 0 && B - i < 0) break;
            if (i % 2) R -= i;
            else B -= i;
            
            res++;
        }
        int r1 = 0;
        R = r; B = b;
        for (int i = 1; ; i++) {
            if (i % 2 && B - i < 0 || i % 2 == 0 && R - i < 0) break;
            if (i % 2) B -= i;
            else R -= i;
            r1++;
        }
        return max(res, r1);
    }
};