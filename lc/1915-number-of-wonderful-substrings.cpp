class Solution {
public:
    long long wonderfulSubstrings(string s) {
        //why xor works? :
        //running_xor has 26 bits representing each char, and set bit means
        //that char has odd freq, and unset bit means even freq
        //now for a substring to be valid, the running frequencies - some
        //previously cached frequencies have atmost one char's freq to be odd
        //so when xor is done ->
        //case 1: both set bits -> means that char had odd freq previouly
        //(0 to that prev), and has odd freq at curr i th index as well (0 to i)
        //so the (prev + 1 to i) substring will have that char freq to be even
        //case 2: both unset bits -> even freq at prev and i so prev + 1 to i
        //also even freq
        //case 3: unset and set bit -> means one of the positons have 0 to that
        //positon have odd freq of that char and other positon (0 to this other 
        //position) has even freq of that char so the substring formed will have
        //odd freq of that char
        long long res = 0;
        unordered_map<int, int> m = {{0, 1}};
        for (int i = 0, running_xor = 0; i < s.size(); i++) {
            running_xor ^= 1 << (s[i] - 97);
            //running_xor ^ map value = number where 0 or 1 set bits (0 or 
            //2^something) so look for running_xor in map
            res += m[running_xor];
            //or numbers who have different bit at a pos of running_xor 
            //eg: running_xor = 1001101...0s (26 total bits)
            //so map must have 0001101.., 1101101.., 1011101.., 1000101..,
            //1001001.., 1001111.., 1001100.., 10011011.., 100110101.., etc
            //since we handled the case no bits different above (meaning
            //prev_pos + 1 to i substr has all chars cnt to be even), now only
            //1 bit position different and rest same means that different
            //bit position char has prev_pos + 1 to i substr freq of that char
            //to be odd and other char freq to be even
            for (int j = 0; j < 26; j++) {
                res += m[running_xor ^ (1 << j)];
            }
            m[running_xor]++;
        }
        return res;
    }
};