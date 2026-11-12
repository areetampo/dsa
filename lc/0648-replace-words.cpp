class Solution {
class Trie {
    class Node {
    public:
        Node* child[26];
        bool eow;
        Node() {
            for (int i = 0; i < 26; ++i) child[i] = nullptr;
            eow = false;
        }
    };
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node* curr = root;
        for (char c : s) {
            if (!curr->child[c - 97]) curr->child[c - 97] = new Node();
            curr = curr->child[c - 97];
        }
        curr->eow = true;
    }
    string pre(string& sentence, int start, int end) {
        Node* curr = root;
        int i = start;
        while (i < end) {
            char c = sentence[i];
            if (curr->child[c - 97]) {
                curr = curr->child[c - 97];
                if (curr->eow) return sentence.substr(start, i - start + 1);
            }
            //eg: "a", sentence = "ba", a is there in sentence but after 0th index so can't be matched as prefix
            else break;//prefix not in trie so [entire word] must be added
            i++;
        }
        return sentence.substr(start, end - start + 1);
    }
};
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie t;
        for (auto &w : dict) t.insert(w);
        string res;
        int n = sentence.length();
        int start = 0;//start of word
        while (start < n) {
            if (start) res += " ";
            int end = start;
            while (end + 1 < n && sentence[end + 1] != ' ') end++;
            res += t.pre(sentence, start, end);
            start = end + 2;
        }
        return res;
    }
};