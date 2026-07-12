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
        // we can use a stack -> bfs
        // [1] -> [2,3] -> [3, 4, 5] -> [4,5,6,7]
        // [1] -> [] -> [2,3] (check the size at this point) -> [4,5,6,7]
        vector<vector<int>> res;
        queue<TreeNode*> level;
        if (root) {
            level.push(root);
        }

        while(level.size()) {
            int level_size = level.size();
            vector<int> level_list;

            for (int i = 0; i < level_size; i++) {   
                TreeNode* curr = level.front();
                cout << "curr: " << curr->val << endl;

                level.pop();
                if (curr->left) {
                    cout << "left: " << curr->left->val << endl;
                    level.push(curr->left);
                }
                if (curr->right) {
                    cout << "right: " << curr->right->val << endl;
                    level.push(curr->right);
                }
                level_list.push_back(curr->val);
            }

            res.push_back(level_list);
        }

        return res;
    }
};
