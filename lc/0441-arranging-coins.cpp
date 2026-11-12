class Solution {
public:
    int arrangeCoins(int n) {
        long long N = n;
        long long k = (sqrt(8*N + 1) - 1) / 2;
        return (k);
    }
};

// alt
// n - no.s (-1-2-3-4....)
// if becomes = 0 then return the i'th term
// if becomes <0 then return i-1'th term 

// alt 2
// math approach
// if the stairs we generated is oh k ht and k base (equal) 
// toatal blocks used -> k(k+1)/2 = n and if the staircase not perfect then
// k(k+1)/2 < n as it's the sum of no.s until ht/base of staircase = or < n
// in the end solving the quad eq and eliminating the n < 0 side, we get: 
// k(k+1)/2 <= n; we get k <= (sqrt(8*n + 1) - 1) / 2
// which gives k as integer for a n that makes perfect stairs and a k with decimal 
// if n isn't a no. to make perfect stairs, the returned integer value of k is 
// perfect as it's the correct no. of stairs made (int) k < (float) k
