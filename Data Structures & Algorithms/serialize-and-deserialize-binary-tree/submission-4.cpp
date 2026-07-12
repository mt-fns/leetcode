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

class Codec {
public:
    void dfsSerialize(TreeNode* root, string& res) {
        if (res.size() > 0) {
            res += ',';
        }
        if (!root) {
            res += 'N';
            return;
        }
        
        res += to_string(root->val); 
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& res, int& index) {
        if (index >= res.size()) {
            return NULL;
        }

        if (res[index] == "N") {
            index++;
            return NULL;
        }

        cout << res[index] << endl;
        TreeNode* curr = new TreeNode(stoi(res[index]));
        index++;
        curr->left = dfsDeserialize(res, index);
        curr->right = dfsDeserialize(res, index);

        return curr;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string token;
        istringstream tokenStream(data);
        char delimiter = ',';

        while (getline(tokenStream, token, delimiter)) {
            vals.push_back(token);
        }

        int index = 0;
        return dfsDeserialize(vals, index);
    }
};
