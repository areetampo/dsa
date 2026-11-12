class Solution {
public:
    int f(string& s, char a, char b, int points) {
        int i = 0, res = 0;//i is for replacing the correct character and j is for traversing (reading) the string
        for (int j = 0; j < s.size(); j++) {
            if (i > 1 && s[i - 2] == a && s[i - 1] == b) {//prev 2 chars match the ab pattern
                i -= 2;//move i two places back
                res += points;
            }
            s[i++] = s[j];//put the char at place
        }
        if (i > 1 && s[i - 2] == a && s[i - 1] == b) {
            res += points;
            i -= 2;
        }
        s = s.substr(0, i);// dbg(s); dbg(res);
        return res;
    }
    int maximumGain(string s, int x, int y) {
        char a = x > y ? 'a' : 'b';
        char b = x > y ? 'b' : 'a';
        if (y > x) {
            swap(x, y);
        }
        //so the seq to look for giving maximum points will be [ab] and have points x and seq giving lesser points [ba] have points y
        return f(s, a, b, x) + f(s, b, a, y);
    }
};