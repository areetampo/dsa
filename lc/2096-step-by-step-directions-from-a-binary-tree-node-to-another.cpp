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
 */
class Solution {
public:
    //using string pointers impo otherwise MLE since returning "" instead of nullptr
    //approach:
    //if end of tree reached return nullptr
    //if src/des never found then nullptr is returned always
    //once src/des is first encountered, the string is built to be returned
    //since src != des means the string will not be empty
    //to built path from src to des is done via lca (lca can be equal to src/des)
    //so from src it will always be 'U' since we are going up to lca
    //from des it will be 'x' which is later replaced by L/R depending on the string
    //coming from left or rightafter returning to parent node
    //now suppose if only one of left/right subtree returns a string and other
    //returns nullptr, then if curr node is src/des means the returned string
    //itself is the correct path
    //NOTE THAT THE PATH IS SRC -> LCA -> DES (LCA CAN BE = SRC/DES) AND RETURNED
    //PATH FROM DES IS IN REVERSE ORDER SO NEEDS TO BE REVERSED ONCE THE LCA IS
    //FOUND
    //now suppose if both left and right subtree return strings then the curr node
    //is lca and the path is complete by string src->lca + rev(lca->des)
    //both_found check otherwise returned strings will keep having x or U being
    //added to even if src to dest path built
    int both_found = 0;
    string* dfs(TreeNode* curr, int src, int des) {
        if (!curr) return nullptr;
        string* l = dfs(curr->left, src, des);
        string* r = dfs(curr->right, src, des);
        if (both_found) return l ? l : r;
        //src/des not found
        if (!l && !r) {
            //src != des
            if (curr->val == src) return new string("U");
            if (curr->val == des) return new string ("x");
            return nullptr;
        }
        //curr is lca
        if (l && r) {
            both_found = 1;
            if (l->back() == 'x') {//left subtree has des node
                l->back() = 'L';
                reverse(l->begin(), l->end());////up to down seq (curr to des)
                *r += *l;
                return r;
            }
            //right subtree has des node
            r->back() = 'R';
            reverse(r->begin(), r->end());//up to down seq (curr to des)
            *l += *r;
            return l;
        }
        //right subtree has src/des
        if (r) {
            if (r->back() == 'x') {//des in right subtree
                r->back() = 'R';
                if (curr->val == src) {//curr is lca
                    both_found = 1;
                    reverse(r->begin(), r->end());//up to down seq (curr to des)
                    return r;
                }
                *r += 'x';
                return r;
            }
            //src in right subtree
            if (curr->val == des) {//curr is lca
                both_found = 1;
                return r;
            }
            *r += 'U';
            return r;
        }
        //left subtree has src/des
        if (l->back() == 'x') {//des in left subtree
            l->back() = 'L';
            if (curr->val == src) {//curr is lca
                both_found = 1;
                reverse(l->begin(), l->end());//up to down seq (curr to des)
                return l;
            }
            *l += 'x';
            return l;
        }
        //src in left subtree
        if (curr->val == des) {//curr is lca
            both_found = 1;
            return l;
        }
        *l += 'U';
        return l;
    }
    string getDirections(TreeNode* curr, int src, int des) {
        return *dfs(curr, src, des);
    }
};
