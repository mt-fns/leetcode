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
    bool isValidBST(TreeNode* root) {
        return dfs(root, {-1001, 1001});
    }

    bool dfs(TreeNode* root, vector<int> range) {
        if (!root) {
            return true;
        }

        if (root->val >= range[1] || root->val <= range[0]) {
            return false;
        }

        return dfs(root->left, {range[0], min(range[1], root->val)}) && dfs(root->right, {max(range[0], root->val), range[1]});
    }
};
