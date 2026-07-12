class Solution {
// cycle chekin
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      if (prerequisites.size() == 0) {
        return true;
      }  
      map<int, vector<int>> dependencies;


      for (auto prereq : prerequisites) {
        if (dependencies.count(prereq[1])) {
            dependencies[prereq[1]].push_back(prereq[0]);
        }
        else {
            dependencies[prereq[1]] = {prereq[0]};
        }
      }
        // cout << dependencies[5][0] << endl;

        for (auto & pair : dependencies) {
            if (!dfs(pair.first, dependencies, {})) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int course,  map<int, vector<int>>& dependencies, set<int> visited) {
        if (visited.count(course)) {
            cout << course << endl;
            return false;
        }

        visited.insert(course);
        for (int i = 0; i < dependencies[course].size(); i++) {
            if (!dfs(dependencies[course][i], dependencies, visited)) {
                return false;
            }
        }

        return true;
    }
};
