class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k & 1 == 0 || k % 5 == 0) return -1;
        int remainder = 0;
for (int len = 1; len <= k; len++) {
    remainder = (remainder * 10 + 1) % k;
    if (remainder == 0)
        return len;   // R(len) is divisible by k!
}
return -1;
    }          
};