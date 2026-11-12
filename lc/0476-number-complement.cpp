class Solution {
public:
    int findComplement(int num) {
        int i = ~0;
        while (num & i) i <<= 1;
        cout << i;
        return ~num & ~i;
    }
};