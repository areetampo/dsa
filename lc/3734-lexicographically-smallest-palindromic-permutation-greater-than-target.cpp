class Solution {
public:
    string rev(string& r) {
        string x = r;
        reverse(x.begin(), x.end());
        return x;
    }
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
        for (int j = c + 1 - 97; j < 26; j++)
            if (f[j]) { big = j + 97; break; }

        if (big == '.') // no bigger char exists, backtrack
            return false; // in case of all smaller: r remains ""

        // add smallest big and others in smallest order
        r += big;
        f[big - 97]--;
        for (int i = 0; i < 26; i++)
            r += string(f[i], i + 97);
        return true;
    }
    string lexPalindromicPermutation(string s, string t) {
        // edge case only 1 char in s and t:
        if (s.size() == 1) return s <= t ? "" : s;

        int f[26] = { 0 };
        for (char& c : s) f[c - 97]++;

        char odd = '.';
        for (int i = 0; i < 26; i++) {
            if (f[i] & 1) {
                if (odd != '.') return ""; // palindrome impossible if >1 odds
                odd = i + 97;
            }
            f[i] >>= 1;
        }

        char t_mid = t[t.size() / 2];
        string t1 = t.substr(0, t.size() / 2),
                t2 = t.substr(t.size() / 2 + (odd != '.'), t.size() / 2);
        string r = "";

        // approach:
        // 1
        // if first half equal to t1 (str made by f[] = t1) use it and
        // check if mid (if exists) and t2 can be used to still make res str lexo greater
        // when case 1 fails to make larger lexo
        // 2
        // use fn()
        // if it gives r = "": not possible to make larger lexo
        // and str made by f[] only contains 1 char (if there were multiple 'big' would be executed)
        // and already tried in case 1 above
        // if r != "": append odd (if exists) and reverse of res to res

        // 1st case
        int t1_f[26] = { 0 };
        for (char& c : t1) t1_f[c - 97]++;

        if (equal(f, f + 26, t1_f)) {
            // first half of r == t1 means: r = t1 + (any odd) + rev_t1
            string rev_t1 = rev(t1); 

            // rev_t1 > t2 and no odd or odd == t_mid
            // rev_t1 >= t2 but odd must exist and odd > t_mid
            if (rev_t1 > t2 && (odd == '.' || odd == t_mid) 
                || odd != '.' && odd > t_mid)
                return t1 + (odd == '.' ? "" : string(1, odd)) + rev_t1;
        }

        // 2nd case
        fn(r, f, t1, 0);

        if (r == "") return "";
        // construct rest of r normally
        r += (odd == '.' ? "" : string(1, odd)) + rev(r);
        return r;
    }
};