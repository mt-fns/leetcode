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
    bool traverse(TreeNode* curr, int p, int q, TreeNode* &res) {
        if (!curr) {
            return false;
        }

        bool found_from_left = traverse(curr->left, p, q, res);
        bool found_from_right = traverse(curr->right, p, q, res);

        if (!res && found_from_left && found_from_right) {
            res = curr;
            return false;
        }

        bool curr_is_target = (curr->val == p || curr->val == q);

        if (!res && (found_from_left || found_from_right) && curr_is_target) {
            res = curr;
            return false;
        }

        return curr_is_target || found_from_left || found_from_right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = nullptr;
        traverse(root, p->val, q->val, res);

        return res;
    }
};
