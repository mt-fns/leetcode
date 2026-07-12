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
/**
*       5 
    2 (-inf, 5)    8 (5, inf)
      4 (2,5)    6 (5,8)
*
*/


public:
    bool recurse(TreeNode* root, int l, int r) {
        if (!root) {
            return true;
        }
        if (root->val >= r || root->val <= l) {
            return false;
        }

        return recurse(root->left, l, root->val) && recurse(root->right, root->val, r);
    }

    bool isValidBST(TreeNode* root) {
        return recurse(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }
};
