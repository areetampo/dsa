class Solution {
public:
    //if a string is represented as 26 bits (26 unique chars, each string
    //len <= 26) where set bit means that char is present in formed 
    //string and 0 means its absent, so total unique chars in each string
    //is equal to cnt of set bits representing that string,
    //now lets say str = abcd so bits = 00..22 0s..01111
    //now lets say we want to add str = a in it, which is represented by
    //00..25 0s..1 so xor of this wich curr str results in 0th bith being
    //unset and total set bits = 3 and len of new string = 5,
    //so if any time the set bits not equal newly formed string length
    //we do not consider taking that string
    //note: some words may have duplicate chars present so just skip them
    int maxLength(vector<string>& v, int i = 0, int str = 0) {
        int str_bits = __builtin_popcount(str);
        if (i == v.size()) return str_bits;
        int curr_word = 0;
        for (char &c : v[i]) curr_word |= 1 << (c - 97);
        int curr_word_bits = __builtin_popcount(curr_word);
        return max(maxLength(v, i + 1, str), 
            curr_word_bits == v[i].size() && 
            __builtin_popcount(str ^ curr_word) == 
                curr_word_bits + str_bits ?
                    maxLength(v, i + 1, str ^ curr_word) : 0);
    }
};