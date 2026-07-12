class Solution {
public:
    // dfs on a node and mark every node visited in the recursion tree in a set
    // iterate through every vertex, check if a vertex is unvisited
    // if it is unvisited, run dfs on it
    // repeat until all nodes visited

    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        map<int, vector<int>> dependencies;
        set<int> seen;

        for (auto & edge : edges) {
            if (dependencies.count(edge[0])) {
                dependencies[edge[0]].push_back(edge[1]);
            }
            else {
                dependencies[edge[0]] = {edge[1]};
            }
            if (dependencies.count(edge[1])) {
                dependencies[edge[1]].push_back(edge[0]);
            }
            else {
                dependencies[edge[1]] = {edge[0]};
            }
        }

        for (int i = 0; i < n; i++) {
            if (!seen.count(i)) {
                cout << i << endl;
                set<int> visited;
                dfs(i, -1, dependencies, seen, visited);
                res++;
            }
        }

        return res;
    }

    void dfs(int curr, int prev, map<int, vector<int>> & dependencies, set<int> & seen, set<int> & visited) {
        if (visited.count(curr)) {
            return;
        }

        visited.insert(curr);
        seen.insert(curr);

        for (int next : dependencies[curr]) {
            if (next != prev) {
                dfs(next, curr, dependencies, seen, visited);
            }
        }
    }   
};
