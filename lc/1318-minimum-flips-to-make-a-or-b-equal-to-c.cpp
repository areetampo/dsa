class Solution {
public:
    int minFlips(int a, int b, int c) {
        // a = 0001100
        // b = 0001010
        //     1110001 = ~a & ~b now & with c will give req 1s to make in a or b
        // c = 0001001    
        //     0001110 = a | b now & with ~c will give req 0s but positions where
        // both a and b have 1 and c has 0 need 1 extra 0 to be made at that pos
        //     0001000 = a & b
        int req_1s = __builtin_popcount(~a & ~b & c),
            req_0s = __builtin_popcount((a | b) & ~c) + 
                __builtin_popcount(a & b & ~c);
        cout << req_0s;
        return req_1s + req_0s;
    }
};