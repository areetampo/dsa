class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        //consider s1 as longer sentence to be made by inserting in s2
        int n = s1.length(), m = s2.length();
        if (n == m) return s1 == s2;
        if (n < m) {swap(s1, s2); swap(n, m);}
        //insert words at start / in b/w / at end of s2 == s1
        //match prefix and suffix in both
        int s = 0, e = m - 1, E = n - 1;
        while (s < n && s1[s] == s2[s]) s++;
        while (0 <= e && s1[E] == s2[e]) e--, E--;
        // cout << s << " " << e << " " << E;
        //can insert at start or end | (with space is neccessary!):
        if (e < 0 && s1[E] == ' ' || s == m && s1[s] == ' ') return 1;
        //fully crossed but no space or equal sentences (were checked above)
        if (s == m || e == -1) return 0;
        //they both landed at a char which is diff in both s1 and s2 (if they had crossed ' ' then s - e > 1)
        //== 1 means they are adjacent and its the same word so whole word: eg: "Luky", "Luccckky"
        if (s - e == 1) return 0;
        if (s - e >= 2) return 1;
        //now inserted word is in middle, s and e are at chars and have ' ' in left, right:
        //NOTE: take out common chars: eg1: "of, xyz of abc" | eg2:
        //A B Z X B B, A B B
        //             e   s
        //normal concat (0, s) + (e+2) gives A B B B but must be A B B, so:
        // int lastPartLen = m - s;//excludes space before the diff char
        // int j = m - 1;
        // // cout << endl << "ll:" << lastPartLen;
        // for (int i = n - 1; i >= n - lastPartLen; i--, j--) {
        //     // cout << endl << s1[i] << " " << s2[j];
        //     if (s1[i] != s2[j]) return 0;
        // }
        // string x = s2.substr(0, s) + s2.substr(j + 1);
        // cout << endl << x;
        return 0;
    }
};//TCs:
// "My name is Haley"
// "My Haley" 
// "of"
// "A lot of words"
// "Eating right now"
// "Eating", "now"
// "abc"
// "abc"
// "Are You Okay"
// "are you okay"
// "a b c"
// "a c"
// "a b c"
// "bc"
// "CwFfRo regR"
// "CwFfRo H regR"
// "B"
// "ByI BMyQIqce b bARkkMaABi vlR RLHhqjNzCN oXvyK zRXR q ff B yHS OD KkvJA P JdWksnH"
// "Aa AAaAaaAaaaAaAAaAA aaaAaAaAAaAaaAA"
// "Aa AA"
// "DN PD"
// "D"
// "A B C D B B"
// "A B B"
// "Luky", "Luccckky"