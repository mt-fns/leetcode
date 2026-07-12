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
    // find where preorder[0] is in inorder ->, inorder[0:mid] is in left while inorder[mid:size] is in right
    // split preorder as well -> preorder[1,mid] is left, preorder[mid,size] is in right
    // note for preorder split, that our inorder's mid simply tells how many element there is on the l/r subtrees
    // when it comes to preorder, the rest of the elements after preorder[0] have to be children of preorder[0] 
    // but we dont know which subtree it is (l/r) split undetermined


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // go through all array, first index i -> first node
        // go next element is going to be the children of i
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        

        TreeNode* res = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        res->left = buildTree(leftPre, leftIn);
        res->right = buildTree(rightPre, rightIn);

        return res;
    }
};
