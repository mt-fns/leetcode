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
    int recurse(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int l = recurse(root->left);
        int r = recurse(root->right);

        if(l < 0 || r < 0) {
            return -1;
        }

        if(abs(l-r) > 1) {
            return -1;
        }

        int height = max(l,r)+1;
        return height;
    }

    bool isBalanced(TreeNode* root) {
        if(recurse(root) < 0) {
            return false;
        }
        return true;
    }

    // 1
    //     2
    //         3
};
