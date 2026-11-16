class Solution {
public:
    class TrieNode {
    public:
        bool eow;
        TrieNode* child[26];
        TrieNode() {
            eow = 0;
            for (int i = 0; i < 26; ++i) child[i] = nullptr;
        }
    };
    TrieNode* root;
    void insert(string s) {
        TrieNode* curr = root;
        for (char& ch : s) {
            if (!curr->child[ch - 97]) curr->child[ch - 97] = new TrieNode();
            curr = curr->child[ch - 97];
        }
        curr->eow = 1;
    }
    bool find(string s, int st, int en) {//start, end indices for substr lookup
        TrieNode* curr = root;
        for (int i = st; i <= en; ++i) {
            char ch = s[i];
            if (!curr->child[ch - 97]) return 0;
            curr = curr->child[ch - 97];
        }
        return curr->eow;
    }
    bool equalSeg(string s, int x, int y, int len) {
        while (len--) if (s[x++] != s[y++]) return 0;
        return 1;
    }
    bool wordBreak(string s, vector<string>& words) {
        int n = s.length();
        root = new TrieNode();
        for (string& w : words) insert(w);
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int i = q.front(); q.pop();
            if (i == n) return 1;//all found in trie so last index inserted in q that is why here 1 return
            for (int k = i; k < n; ++k) {//look for all possible next word segments to add in q
                int j = k;
                if (find(s, i, j)) {//if segment found, don't stop here
                    int len = j - i + 1;
                    //go until all duplicate segments of that segment in string and put last next idx in q
                    while (j + len < n && equalSeg(s, k, j + 1, len) && find(s, j + 1, j + len)) j += len;
                    cout << i << " " << j + 1 << endl;
                    q.push(j + 1);
                }
            }
        }
        return 0;
    }
};