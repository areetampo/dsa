class Solution {
public:
    int numSteps(string s) {
        int i = s.length(), carry = 0, res = 0;
        while (--i > 0) {
            if (s[i] == '0') {
                if (carry) res += 2;//it would become 1 then 2 steps req (1 + 1 -> 0 -> div by 2)
                //note that carry persists till i = 0 if even a single '1' exists in string
                //10001 carry = 0
                //10010 carry = 1
                //10100 carry = 1
                //11000 carry = 1
               //100000 carry = 1
                else res++;
            } else {
                if (carry) res++;
                else res += 2;
                carry = 1;
            }
        }
        //i = 0 now and will always be 1 since msb
        if (carry) res++;
        return res;
    }
};