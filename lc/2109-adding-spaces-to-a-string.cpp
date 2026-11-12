class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        //approach: eg: "AbcAbAbcdAd" spaces = [3,5,9] -> n = 3
        //put spaces at start -> "   AbcAbAbcdAd"
        //i = 0 and j = 0 and spaces[j] = 3 so
        //swap (first word's chars until < n + spaces[j] which is start of second 
        //word after all swaps, i - n + j -> which represents swap each i with char 
        //n (total spaces) back + j which is 0 meaning no spaces are inserted as of
        //now which have to be taken care of, in later words when spaces are there,
        //j would be increased meanng take care of j num of spaces and start swaps
        //after that) -> "Abc   AbAbcdAd"
        //now j = 1 and spaces[j] = 5 and i = 6 (at A) so now swap :
        //(i -> end of second word or until < n + spaces[j] which is until start of
        //third word, i - n + j) -> the i - n + j means that from curr char, n
        //(spaces) back + j (now j would be 1 representing that move forward 1 
        //since 1 space has alr been inserted and dont touch it) -> "Abc Ab  AbcdAd"
        //----and so on.... now after each word, where is i put at?
        //spaces[j] tells start of each new word (except obv the first word which 
        //is at index 0) and since n spaces are inserted at start and we traverse
        //the string while swapping chars at back, i can keep moving organically
        int n = spaces.size();
        s = string(n, ' ') + s;
        for (int i = n, j = 0; j < n; j++) {
            while (i < n + spaces[j]) swap(s[i], s[i - n + j]), i++;
        }
        return s;
    }
};