class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(); // even
        int ls = 0, rs = 0, lq = 0, rq = 0;
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') lq++;
                else ls += num[i] - '0';
            } else {
                if (num[i] == '?') rq++;
                else rs += num[i] - '0';
            }
        }

        // alice: sum not eq
        // bob: sum eq

        // case 0
        // odd number of total ?: alice always wins since she will have last move to unequalize and equals
        if ((lq + rq) & 1) return 1;

        // 1
        // greater sum side has more or equal ?: alice
        if (ls > rs && lq >= rq || ls < rs && lq <= rq) return 1;

        // 2
        // sum equal: bob wins only if total ? even and lq == rq
        if (ls == rs) return lq != rq;

        // 3
        // greater sum side less ?
        // so theres a diff that needs to be equalized with diff of ?
        int ds = abs(ls - rs), dq = abs(lq - rq);
        // note that its known dq is even here
        // alice starts first
        // alice adn bob both fill dq/2 positions
        // number placed in [0, 9]
        // alice can keep placing 9s and if dq/2 * 9 > ds bob cant equalize
        // dq/2 * 9 < ds alice can keep placing 0s and bob cant equalize
        // only in dq/2 * 9 == ds can bob equalize: whatever alice places bob places a number so sum == 9
        // eg alice places 0 bob places 9 or alice places 6 bob places 3 or a: 9 b: 0
        // since theres dq/2 ? for both dq/2 * 9 == ds bob always wins
        return dq / 2 * 9 != ds;
    }
};