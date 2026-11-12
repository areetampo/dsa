/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        long mid = i+(j-i)/2;//i guess mid to be the number
        while (i <= j) {
            mid = i+(j-i)/2;//to prevent integer overflow
            if (guess(mid) != 0) {
                if (guess(mid) == -1) {
                    j = mid - 1;
                }
                else {//+1 returned by guess
                    i = mid + 1;
                }
            }
            else return mid;//= 0 condition meaning my guess correct
        }
        return mid;
    }
};