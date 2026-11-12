class Solution {
public:
    class N {
    public:
        bool eow = 0;
        N* child[26] = {};
    };
    N* r;
    void insert(string w) {
        N* C = r;
        for (char c : w) {
            if (C->child[c - 97] == nullptr)
                C->child[c - 97] = new N();
            C = C->child[c - 97];
        }
        C->eow = 1;
    }
    void search(int i, vector<int>& t, string& s, N* c) {
        if (i == s.length()) {
            //last word's eow node never found and idx = s.lngth() never inserted in t:
            if (t[t.size() - 1] != s.length()) return;
            //NOTE s.size() was pushed as idx since it was supposed to be the start of new substring after space so removing it
            string r = "";
            for (int idx = 0; idx < t.size() - 1; idx++) {
                //start idx, len of substr + space
                r += s.substr(t[idx], t[idx + 1] - t[idx]) + " ";
            }
            r.pop_back();//last space
            res.push_back(r);
            return;
        }
        if (c->child[s[i] - 97] == nullptr) return;
        if (c->child[s[i] - 97]->eow) {
            t.push_back(i + 1);
            search(i + 1, t, s, r);//start of new word now
            t.pop_back();
        }
        search(i + 1, t, s, c->child[s[i] - 97]);//going in same word
    }
    vector<string> res;
    vector<string> wordBreak(string s, vector<string>& d) {
        res = vector<string>();
        r = new N();
        for (string& w : d) insert(w);
        //has starting indices of each word to be concat as a string for a single element of res:
        vector<int> t = {0};//first index is 0
        search(0, t, s, r);
        return res;
    }
};