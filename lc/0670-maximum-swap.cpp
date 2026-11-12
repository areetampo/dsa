class Solution {
public:
    int maximumSwap(int num) {
        //find rightmost largest number and replace with leftmost (first) appearance of a number less than it
        int i = pow(10, (int)log10(num)), location;//location of rightmost largest (after dec seq, eg: 98368 -> last 8 largest)
        while (i > 1 && (num / i) % 10 >= (num / (i / 10)) % 10) i /= 10;
        int mx = 0;
        while (i) {
            //use = as well so rightmost obtained
            if (mx <= (num / i) % 10) mx = (num / i) % 10, location = i;
            i /= 10;
        }
        i = pow(10, (int)log10(num));
        while (i && ((num / i) % 10) >= mx) i /= 10;
        //swap i and location only if i at left of location (smaller val position at left)
        if (i == 0 || location >= i) return num;
        cout << i << " " << location;
        int diff = ((num / location) % 10) - ((num / i) % 10);//diff of numbers
        //add at i and subtract at location posisions
        //for 10909091
        //          i = 10
        //    l = 10000000, diff = 9 - 1 = 8
        num += i * diff - location * diff;
        return num;
    }
};