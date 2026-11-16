class Solution {
public:
    bool isRectangleOverlap(vector<int>& a, vector<int>& b) {
        // [bl xy, tr xy]
        // let a be left of b
        if (a[0] > b[0]) swap(a, b);
        int ablx = a[0], ably = a[1],
            abrx = a[2], abry = a[1],
            atlx = a[0], atly = a[3],
            atrx = a[2], atry = a[3],
            bblx = b[0], bbly = b[1],
            bbrx = b[2], bbry = b[1],
            btlx = b[0], btly = b[3],
            btrx = b[2], btry = b[3];

            // cout <<( btlx < abrx && btly > abry);

        return btlx < abrx && btly > abry &&
                bblx < atrx && bbly < atry;
    }
};