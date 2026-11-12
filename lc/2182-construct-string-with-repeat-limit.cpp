class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int v[26] = {0};
        for (char& c : s) v[c - 97]++;
        // for (int &i : v) cout << i << " "; cout << "\n";
        s.resize(0);
        //each i is the new largest character which is to be inserted min(its freq,
        //limit) times then j is the next char to create gap between i's curr set
        //of chars and next set of min(freq, limit) chars
        for (int i = 25; i >= 0; ) {
            //0 freq chars skipped
            while (i >= 0 && v[i] == 0) i--;
            int j = i - 1;
            while (i >= 0 && v[i] > 0 && j >= 0) {
                //skip in b/w chars if 0 freq
                while (j >= 0 && v[j] == 0) j--;
                //add char i
                s += string(min(v[i], limit), i + 97);
                v[i] -= min(v[i], limit);
                //add the intermediate char
                if (v[i] > 0 && j >= 0 && v[j] > 0) {
                    s += string(1, j + 97);
                    v[j]--;
                }
            }
            //now if at a position where intermediate chars exhausted, that means
            //if the curr char i's freq is > 0 AND WAS NOT USED LASTLY
            //NOTE THAT IF THE ABOVE WHILE LOOP DOESNT HAVE j >= 0 CONDITION
            //THEN IT WILL NOT EXIT AND KEEP ON ADDING THE i CHAR TO STRING,
            //now that it has exited, if j == - 1 (intermediate chars exhausted)
            //and i chars is available then add min(freq, limit) of it string if
            //2 cases: 
            //1: empty string eg : "aaaa" limit = 3
            //2: its not the last taken char from above while loop
            //and then break
            if (j == -1 && v[i] > 0) {
                // cout << "...\n";
                if (s.empty() || s.back() != i + 97) 
                    s += string(min(v[i], limit), i + 97);
                break;
            }
        }
        return s;
    }
};