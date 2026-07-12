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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> level;
        vector<vector<int>> lvl_order;
        vector<int> res;

        if (root) {
            level.push(root);
        }

        while (level.size()) {
            int level_size = level.size();
            vector<int> curr_lvl;
            
            for (int i = 0; i < level_size; i++) {
                TreeNode* curr = level.front();
                level.pop();
                if (curr->left) {
                    level.push(curr->left);
                }
                if (curr->right) {
                    level.push(curr->right);
                }
                curr_lvl.push_back(curr->val);
            }

            lvl_order.push_back(curr_lvl);
        }
        
        for (const auto & lvl : lvl_order) {
            res.push_back(lvl[lvl.size()-1]);
        }

        return res;
    }
};
