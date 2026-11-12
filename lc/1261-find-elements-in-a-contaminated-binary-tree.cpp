/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
                           0
                /                   \
               1                     2
        /            \         /            \
       3              4       5             6
      / \            / \     / \           / \
      7 8            9 10   11 12         13 14

      converting to 1 based

                          1
                /                   \
               2                     3
        /            \         /            \
       4              5       6             7
      / \            / \     / \           / \
      8 9           10  11  12 13         14 15

      par i children are i * 2, i * 2 + 1 -> even, odd
      so odd val is a right child and even val is a left child
      for any child j -> par is i / 2
      so a whole string or L-R can be constructed and then reversed to be top-down
      and from root node, level wise traversed, if stringis parsed and node exits
      return true otherwise false
      now note that breakdown a number to form its path to root is same as that number's
      binary representation (root to node == bits left to right)
      eg : 13 = 1101 that means msb 1 being root only then 101 means R-L-R
 */

class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        this->root = root;
    }

    bool find(int target, int bit = -2, TreeNode* ro = nullptr) {
        // cout << target << " " << bit << "\n";
        if (bit == -2) return find(target + 1, log2(target + 1) - 1, root);
        //-1 cuz start from 2nd bit from left side, 
        if (ro == nullptr) return false;
        if (bit == -1) return true;
        return find(target, bit - 1, 
            (target & (1 << bit)) == 0 ? ro->left : ro->right);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */