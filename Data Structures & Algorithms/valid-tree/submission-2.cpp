class Solution {
public:
    // dfs cycle check
    // must be reachable
    // run dfs from one node (any node) and keep track of visited set

    bool validTree(int n, vector<vector<int>>& edges) {
        if (!edges.size()) {
            return true;
        }

        set<int> seen;
        map<int, set<int>> dependencies;

        for (auto edge : edges) {
            dependencies[edge[0]].insert(edge[1]);
            dependencies[edge[1]].insert(edge[0]);
        }

        if (!dfs(edges[0][0], -1, seen, {}, dependencies)) {
            return false;
        }

        cout << seen.size() << endl;

        if (seen.size() != n) {
            return false;
        }

        return true;
    }

    bool dfs(int i, int prev, set<int> & seen, set<int> visited, map<int, set<int>> & dependencies) {
        if (visited.count(i)) {
            cout << i << endl;
            return false;
        }
        seen.insert(i);
        visited.insert(i);

        for (int j : dependencies[i]) {
            if (prev != j) {
                if (!dfs(j, i, seen, visited, dependencies)) {
                    return false;
                }
            }
        }

        return true;
    }
};
