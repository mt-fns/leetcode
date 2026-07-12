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
    // do a bfs on the root
    // recurse:
    // max(recurse left, recurse right, root + path left + path right)
    //
    // path:
    // max of path(l), path(r)
    int maxPathSum(TreeNode* root) {
        return dfs(root);
    }

    int dfs(TreeNode* root) {
        vector<int> res;
    
        if (root->left) {
            res.push_back(dfs(root->left));
        }
        if (root->right) {
            res.push_back(dfs(root->right));
        }

        int maxRoot = root->val;
        res.push_back(maxRoot);

        if (root->left && root->right) {
            res.push_back(maxRoot + maxPath(root->left) + maxPath(root->right));
        }
        if (root->left) {
            res.push_back(maxRoot + maxPath(root->left));
        }
        if (root->right) {
            res.push_back(maxRoot + maxPath(root->right));
        }

        int max_res = -1000000;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > max_res) {
                max_res = res[i];
            }
        }
        
        return max_res;
    }

    int maxPath(TreeNode* root) {
        vector<int> res;
        res.push_back(root->val);

        if (root->left && root->right) {
            int pathVal = max(maxPath(root->left), maxPath(root->right));
            res.push_back(root->val + pathVal);
        }
        else if (root->right && !root->left) {
            int pathVal = maxPath(root->right);
            res.push_back(root->val + pathVal);
        }
        else if (root->left && !root->right) {
            int pathVal = maxPath(root->left);
            res.push_back(root->val + pathVal);
        }

        int max_res = -1000000;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] > max_res) {
                max_res = res[i];
            }
        }

        return max_res;
    }
};
