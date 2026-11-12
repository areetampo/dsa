class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int nest = 0;
        for (char &c : s) {
          if (c == '(') ++nest;
          else if (c == ')') --nest;
          res = max(nest, res);
        }
        return res;
    }
};