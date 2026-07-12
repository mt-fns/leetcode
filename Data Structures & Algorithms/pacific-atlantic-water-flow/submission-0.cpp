class Solution {
public:
    int ROWS;
    int COLS;
    vector<vector<int>> grid;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;

        ROWS = heights.size();
        COLS = heights[0].size();
        grid = heights;

        // all cells visitable from pacific
        set<vector<int>> pc_set;
        // from atlantic
        set<vector<int>> atl_set;
        
        // check all top/bottom
        for (int k = 0; k < COLS; k++) {
            dfs(0, k, pc_set, -1);
            dfs(ROWS-1, k, atl_set, -1);
        }

        // check all left/right cells
        for (int k = 0; k < ROWS; k++) {
            dfs(k, 0, pc_set, -1);
            dfs(k, COLS-1, atl_set, -1);
        }

        // all cells that can be visited from pc/atl
        for (const auto& cell : pc_set) {
            if (atl_set.count(cell)) {
                res.push_back(cell);
            }
        }


        return res;
    }


    void dfs(int i, int j, set<vector<int>>& visited, int prevHeight) {
        if (i < 0 || j < 0 || i >= ROWS || j >= COLS || visited.count({i, j}) || grid[i][j] < prevHeight) {
            return;
        }

        visited.insert({i, j});
        dfs(i+1, j, visited, grid[i][j]);
        dfs(i, j+1, visited, grid[i][j]);
        dfs(i-1, j, visited, grid[i][j]);
        dfs(i, j-1, visited, grid[i][j]);
    }
};
