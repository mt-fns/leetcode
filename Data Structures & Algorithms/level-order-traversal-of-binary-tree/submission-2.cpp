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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        queue<TreeNode*> q;
        vector<int> curr_vec = {};

        if (root) {
            q.push(root);
        }
           
        while (!q.empty()) {
            vector<int> curr_lvl;

            for (int i = q.size(); i > 0; i--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr) {
                    curr_lvl.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }

            if (curr_lvl.size()) {
                res.push_back(curr_lvl);
            }
        }


        return res;
    }
};
