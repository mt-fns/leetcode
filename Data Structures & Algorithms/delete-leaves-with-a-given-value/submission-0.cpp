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
    TreeNode* dfs(TreeNode* curr, int target) {
        if (!curr) {
            return nullptr;
        }

        curr->left = dfs(curr->left, target);
        curr->right = dfs(curr->right, target);

        if (curr->val == target && !curr->left && !curr->right) {
            return nullptr;
        }
        
        return curr;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};