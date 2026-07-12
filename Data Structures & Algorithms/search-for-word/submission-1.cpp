class Solution {
public:
    set<pair<int, int>> selected;
    int n_row;
    int n_col;

    bool exist(vector<vector<char>>& board, string word) {
        // bfs
        n_row = board.size();
        n_col = board[0].size();

        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                if (dfs(i, j, 0, word, board)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int i, int j, int curr_index, string word, vector<vector<char>>& board) {
        if (curr_index == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= n_row || j >= n_col || selected.count({i, j}) || board[i][j] != word[curr_index]) {
            return false;
        }

        selected.insert({i, j});

        if (dfs(i + 1, j, curr_index + 1, word, board) 
            || dfs(i, j + 1, curr_index + 1, word, board) 
            || dfs(i - 1, j, curr_index + 1, word, board)
            || dfs(i, j - 1, curr_index + 1, word, board)) 
        {
            return true;
        }

        selected.erase({i, j});
        return false;
    }
};
