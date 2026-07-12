class Solution {
public:
    int n_rows;
    int n_cols;

    int numIslands(vector<vector<char>>& grid) {
        n_rows = grid.size();
        n_cols = grid[0].size();
        int count = 0;

        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }

    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<vector<int>> q;
        q.push({i, j});

        while (!q.empty()) {
            vector<int> curr = q.front();
            grid[curr[0]][curr[1]] = '0';
            q.pop();
            vector<vector<int>> neighbours = {{curr[0]+1, curr[1]}, {curr[0], curr[1]+1}, {curr[0]-1, curr[1]}, {curr[0], curr[1]-1}};

            for (auto n : neighbours) {
                if (n[0] < 0 || n[1] < 0 || n[0] >= n_rows || n[1] >= n_cols || grid[n[0]][n[1]] != '1') {
                    continue;
                }
                q.push({n[0], n[1]});
            }
        }
    }
};
