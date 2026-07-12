/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<int, Node*>& node) {
        if (!curr) {
            return NULL;
        }

        Node* copyNode;
    
        if (!node.contains(curr->val)) {
            copyNode = new Node(curr->val);
            node[curr->val] = copyNode;
        }
        else {
            copyNode = node[curr->val];
        }

        for (const auto & n : curr->neighbors) {
            Node* n_copy;

            if (!node.contains(n->val)) {
                n_copy = dfs(n, node);
            }
            else {
                n_copy = node[n->val];
            }

            copyNode->neighbors.push_back(n_copy);
        }

        return copyNode;
    }

    Node* cloneGraph(Node* node) {
        // (1,2), (2,3), (3,1)
        // pass in all nodes not just parent -> could be via a map or a vector
        // O(V(V+E))
        // dfs O(V + E)
        // wat  ch out for parent node when adding to neighbour -> dfs contains parent node that we passed in?
        unordered_map<int, Node*> nodes;
        return dfs(node, nodes);
    }
};
