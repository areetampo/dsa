class Solution {
public:
    int distinctSubseqII(string s) {
        //the logic here is:
        //for each char, the subseq till that point will be:
        //sub till previous index + subseq involvng this char,
        //now the 'subseq involving this char' = sub till prev idx + 1
        //where: sub till prev idx = res itself
        //and the + 1 is the single char itself 
        //but there's a catch, if a char has appeared previously, subseq
        //formed by taking it at those positions are stored in f[] which
        //must be subtracted from res
        //eg:
        //total subseq till before this :    0  1  2  5  11 20 39 73 
        //string :                           a  a  b  c  b  a  c  a
        //subseq formed by including this :  1  1  3  6  7  19 34 53
        //res = 73 + 53 = 126
        //explanation:
        //lets consider the subseq formed till second a = 2
        //a aa
        //lets consider the subseq formed till b = 5
        //a aa | ab aab b
        //till c = 11: (just adding c to existing subseq which doubles the
        //total subseq and +1 for the new cahr being considered individually)
        //a aa ab aab b | ac aac abc aabc bc c
        //now till the next b:
        //prev all subseqs + taking b as individual char 'b' and these ->
        //ab bb cb aab abb acb bcb aabb aacb abcb aabcb
        //now notice that how all the subseq formed till prev b are being 
        //repeated cuz all the seq formed till prev of that prev b are getting
        //included again with this b so must be subtracted must subtract 
        //subseqs till prev of all prev occurences of curr el from f[]
        long long f[26] = {0}, res = 0, mod = 1000000007;
        for (char& c : s) {
            int seq_with_c = (((res - f[c - 97] + 1) % mod) + mod) % mod;
            res = (res + seq_with_c) % mod; // res = res*2 + 1 - f[]
            f[c - 97] = (f[c - 97] + seq_with_c) % mod;
            // cout << f[c - 97] << " " << res << "\n";
        }
        return res;
    }
};