class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(vc.rbegin(), vc.rend());
        sort(hc.rbegin(), hc.rend());
        int v = 0;
        int h = 0;
        int vPieces = 1;
        int hPieces = 1;
        long long cost = 0;
        while (v < vc.size() && h < hc.size()) {
            if (vc[v] > hc[h]) {
                cost += vc[v] * vPieces;
                hPieces++;
                v++;
            } else {
                cost += hc[h] * hPieces;
                vPieces++;
                h++;
            }
        }
        while (v < vc.size()) {
            cost += vc[v] * vPieces;
            v++;
        }
        while (h < hc.size()) {
            cost += hc[h] * hPieces;
            h++;
        }
        return cost;
    }
};