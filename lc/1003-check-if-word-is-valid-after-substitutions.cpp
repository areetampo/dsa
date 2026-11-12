class Solution {
public:
    bool isValid(string s) {
        int i = 0;//i is for replacing the correct character and j is for traversing (reading) the string
        for (int j = 0; j < s.size(); j++) {
            if (i > 2 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c') {//prev 3 chars match the abc pattern
                i -= 3;//move i 3 places back
            }
            s[i++] = s[j];//put the char at place
        }
        if (i > 2 && s[i - 3] == 'a' && s[i - 2] == 'b' && s[i - 1] == 'c') {
            i -= 3;
        }
        cout << i;
        return !i;
    }
};