class Solution {
public:
    vector<pair<int,int>> neigh = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (j >= grid[0].size() || j < 0 || i < 0 || i >= grid.size()) {
            return;
        }

        grid[i][j] = '0';

        for (const auto & n : neigh) {
            int new_i = i + n.first;
            int new_j = j + n.second;

            if (new_j >= grid[0].size() || new_j < 0 || new_i < 0 || new_i >= grid.size() ) {
                continue;
            }

            if (grid[new_i][new_j] == '1') {
                dfs(new_i, new_j, grid);
            }
        }
        
    }   

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(i,j,grid);
                    res++;
                }
            }
        }

        return res;
    }
};
