class Solution {
public:
    class TrieNode {
    public:
        int prefixCnt = 0;
        TrieNode* v[26] = {};
        // TrieNode() {
        //     prefixCnt = 0;
        //     // v = vector<TrieNode*>(26, nullptr);
        // }
        // TrieNode(char c) : TrieNode() {
        //     v[c - 97] = new TrieNode();
        // }
    };
    TrieNode* root;
    void insert(TrieNode* r, string& w) {
        TrieNode* c = r;
        // cout << w << endl;
        for (char &C : w) {
            if (c->v[C - 97] == nullptr) c->v[C - 97] = new TrieNode();
            (c->v[C - 97]->prefixCnt)++;//all chars to be marked eow to consider all prefixes
            // cout << C << " " << c->v[C - 97]->prefixCnt << endl;
            c = c->v[C - 97];
        }
    }
    int prefixesFound(TrieNode* r, string& w) {
        TrieNode* c = r;
        int res = 0;
        for (char &C : w) {
            // if (c->v[C - 97] == 0) break;//word seq will never be broken since the words inserted in the trie are char by char until the end of the word itself
            res += c->v[C - 97]->prefixCnt;//all chars to be marked eow to consider all prefixes
            c = c->v[C - 97];
        }
        return res;
    }
    vector<int> sumPrefixScores(vector<string>& w) {
        root = new TrieNode();
        vector<int> res;
        for (string& W : w) insert(root, W);
        for (string& W : w) res.push_back(prefixesFound(root, W));
        return res;
    }
};