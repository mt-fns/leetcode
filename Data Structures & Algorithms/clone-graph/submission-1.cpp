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
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }
 
        Node* res = new Node(node->val);

        // keep track of visited list as well (check if already visited -> node exists -> add that node to neighbour)
        queue<Node*> q;
        queue<Node*> q_new;
        map<int, Node*> visited;

        q.push(node);
        q_new.push(res);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            Node *curr_new = q_new.front();
            q_new.pop();

            for (int i = 0; i < curr->neighbors.size(); i++) {
                int curr_val = curr->neighbors[i]->val;

                if (!visited.count(curr_val)) {
                    Node* neigh_new = new Node(curr_val);
                    q.push(curr->neighbors[i]);
                    q_new.push(neigh_new);
                    curr_new->neighbors.push_back(neigh_new);
                    visited[curr_val] = neigh_new;
                }
                else {
                    curr_new->neighbors.push_back(visited[curr_val]);
                }
            }
        }

        return res;
    }
};
