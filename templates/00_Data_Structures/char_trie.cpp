// Standard lowercase-alphabet Trie — supports insert, exact search, and
// prefix search. Classic building block for word-dictionary / autocomplete
// problems, longest common prefix problems, etc.
//
// Complexity: insert/search/startsWith are all O(|s|) per call.
//
// Usage:
//   Trie trie;
//   trie.insert("apple");
//   trie.search("apple");      // true  — exact word inserted
//   trie.search("app");        // false — inserted only as a prefix
//   trie.startsWith("app");    // true  — some inserted word starts with "app"
//
// Assumes lowercase 'a'-'z' only. For other alphabets/cases, change the
// nxt[26] size and the `c - 'a'` mapping below.
struct Trie {
  struct Node {
    i32 nxt[26];
    bool end;

    Node() {
      memset(nxt, -1, sizeof(nxt));
      end = false;
    }
  };

  vector<Node> t;

  Trie() { t.emplace_back(); } // node 0 is always the root

  // Insert s into the trie, creating nodes as needed, and mark the final
  // node as a word end.
  void insert(string s) {
    i32 v = 0;
    trav(c, s) {
      i32 x = c - 'a';
      if (t[v].nxt[x] == -1) {
        t[v].nxt[x] = sz(t); // new node's index == current size, before the push
        t.emplace_back();
      }
      v = t[v].nxt[x];
    }
    t[v].end = true;
  }

  // True iff s was inserted as a complete word (not just as a prefix of
  // something longer).
  bool search(string s) {
    i32 v = 0;
    trav(c, s) {
      i32 x = c - 'a';
      if (t[v].nxt[x] == -1) return false;
      v = t[v].nxt[x];
    }
    return t[v].end;
  }

  // True iff s is a prefix of at least one inserted word (including being a
  // full word itself).
  bool startsWith(string s) {
    i32 v = 0;
    trav(c, s) {
      i32 x = c - 'a';
      if (t[v].nxt[x] == -1) return false;
      v = t[v].nxt[x];
    }
    return true;
  }
};
