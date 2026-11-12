class Solution {
public:
    int totalMoney(int n) {
        return 
        (((n/7) > 0) ? (n/7) * (56 + 7 * ((n/7) - 1)) / 2 : 0) + ((n%7 > 0) ? ((n%7)*((n%7)+1)/2) + ((n/7) * (n%7)) : 0);
    }
    // full weeks -> (28) + (28 + 7) + (28 + 14) + ...... 
    // no. of times full week appears = (int) (n/7)
    // total money saved in bank in full weeks = Arithmetic progression (AP) sum = fullWeeks * (first term + last term) / 2 
    // where fullWeeks = n/7, first term = 28 (saved in 1st full week), 
    // last term = first term + commonDiff * ((fullWeeks or terms in AP) - 1), terms in AP = n/7 = number of full weeks
    // ((n/7) > 0) ? (n/7) * (28 + (28 + 7 * ((n/7) - 1))) / 2 : 0 
    // [(28 + 7 * ((n/7) - 1)) is the last term of AP]

    // leftover days -> always < 7 since they are not part of full weeks
    // so there would 1 + 2 + 3 ... depending on how many leftover days are there, can be from 1 to 6 so we add those:
    // sum of first n % 7 natural numbers + 
    // the 'subsequent week added sum in it' which would be: number of days in non full week (leftover days) * (n / 7)
    // (n/7 as for week 1 it would be 0 then for week 2 it would be 1 and so on...)
    // (n%7 > 0) ? ((n%7)*((n%7)+1)/2) + ((n/7) * (n%7)) : 0
};