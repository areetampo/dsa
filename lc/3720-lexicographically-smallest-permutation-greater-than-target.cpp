class Solution {
public:
    bool fn(string& r, int* f, string& t, int i) {
        // base case
        // s and t same size so hitting base case means equal string was produced
        // this false return will make the prev fn call check for a big making either:
        // ig theres a big smallest lexo larger than t produced
        // or spiraled with false returns making r empty
        if (i == t.size()) return false;
        // check if same char available
        char c = t[i];
        if (f[c - 97]) {
            r += c;
            f[c - 97]--;
            if (fn(r, f, t, i + 1))
                return true;
            f[c - 97]++;
            r.pop_back();
        } 
        // check if just a bigger char avilable
        char big = '.';
        for (int j = c + 1 - 97; j < 26; j++) {
            if (f[j]) {
                big = j + 97; break;
            }
        }
        if (big == '.') { // no bigger char exists, backtrack
            return false;
        } else { // add smallest big and others in smallest order
            r += big;
            f[big - 97]--;
            for (int i = 0; i < 26; i++)
                r += string(f[i], i + 97);
            return true;
        }
    }
    string lexGreaterPermutation(string s, string t) {
        int f[26] = { 0 };
        for (char& c : s) f[c - 97]++;
        string r = "";
        fn(r, f, t, 0);
        return r;
    }
};