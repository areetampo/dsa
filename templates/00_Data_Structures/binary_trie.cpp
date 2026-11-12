// Binary Trie (bitwise trie) over fixed-width integers — supports inserting
// values and finding the maximum XOR against any previously inserted value.
// Classic building block for "maximum XOR pair", "max XOR subarray" (combined
// with prefix XORs), and similar problems.
//
// Complexity: insert/maxXor are both O(BITS) per call, O(BITS) extra nodes
// per insert in the worst case.
//
// Usage:
//   BinaryTrie trie;
//   trie.insert(5);
//   trie.insert(12);
//   i32 best = trie.maxXor(9);   // largest (9 ^ y) over inserted y's
//
// For 64-bit values: change BITS to 64 and swap every i32 in this struct
// (including insert/maxXor's parameter and return types) to i64.
struct BinaryTrie {
  static const int BITS = 32; // number of bits considered per inserted value, MSB first

  // Each node holds two children indices into `t`: nxt[0] for the next bit
  // being 0, nxt[1] for it being 1. -1 means that child doesn't exist yet.
  struct Node {
    i32 nxt[2];
    Node() { nxt[0] = nxt[1] = -1; }
  };

  vector<Node> t;

  BinaryTrie() { t.emplace_back(); } // node 0 is always the root

  // Insert x bit by bit, from MSB to LSB, creating new nodes as needed.
  void insert(i32 x) {
    i32 v = 0; // current node, starting at root
    fr(b, BITS - 1, 0) {
      i32 bit = (x >> b) & 1;
      if (t[v].nxt[bit] == -1) {
        t[v].nxt[bit] = sz(t); // new node's index == current size, before the push
        t.emplace_back();
      }
      v = t[v].nxt[bit];
    }
  }

  // Return the max value of (x ^ y) over every y inserted so far.
  // Greedily descends toward the opposite bit at each level whenever that
  // child exists, since flipping a higher bit always beats any combination
  // of lower bits.
  i32 maxXor(i32 x) {
    i32 v = 0, ans = 0;
    fr(b, BITS - 1, 0) {
      i32 bit = (x >> b) & 1;
      if (t[v].nxt[bit ^ 1] != -1) {
        ans |= (1 << b);
        v = t[v].nxt[bit ^ 1];
      } else {
        v = t[v].nxt[bit];
      }
    }
    return ans;
  }
};
