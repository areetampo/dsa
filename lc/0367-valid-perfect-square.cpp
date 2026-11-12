class Solution {
public:
    bool isPerfectSquare(int num) {
        long long i = 0, j = num;
        while (i<=j) {
            long long k = (((i+j)/2) * ((i+j)/2));
            if (k == num)
            return true;
            if (k > num)
                j = (i+j)/2 - 1;
            else i = (i+j)/2 + 1;
        }
        return false;
    }
};

//alt 
// sq no. = sum of odds 
// so keep ding num - odd no.s if it reaches 0 then return true and if < 0 then false but has O(sqrt(n))

