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
    // special case handling when the current node is a target and is also the parent
    // of the other node

    bool recurse(TreeNode* curr, TreeNode* p, TreeNode* q, TreeNode*& lca) {
        if (!curr) {
            return false;
        }

        // case where left and right is true -> curr node is lca
        bool l = recurse(curr->left, p, q, lca);
        bool r = recurse(curr->right, p, q, lca);
        bool curr_is_valid = (curr->val == p->val) || (curr->val == q->val);

        if (((l && r) || (r && curr_is_valid) || (l && curr_is_valid))) {
            cout << curr->val << endl;
            lca = curr;
        }

        return l || r || curr_is_valid;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p or q return true
        // check if root has both true
        TreeNode *lca = root;
        recurse(root, p, q, lca);

        // if (lca == nullptr) {
        //     cout << "Hello" << endl;
        // }

        return lca;
    }
};
