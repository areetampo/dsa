class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //ab rook cd bishop ef queen
        if (a == e) {//same row
            if (c != a || (b < f && (d < b || f < d)) || (f < b && (d < f || b < d))) return 1;
        }
        if (b == f) {//same col
            if (d != b || (a < e && (c < a || e < c)) || (e < a && (c < e || a < c))) return 1;
        }
        if (abs(c-e) == abs(d-f)) {
            //blocked by rook (in between)
            if (a-c == b-d && (c < a && a < e || e < a && a < c)) return 2;
            if (c-a == b-d && (c < a && a < e || e < a && a < c)) return 2;
            //no block
            return 1;
        }
        return 2;
    }
};