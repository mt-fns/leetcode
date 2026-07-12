class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> cols;
        map<int, set<int>> rows;

        for (int i = 0; i < board[0].size(); i++) {
            rows[i] = {};
        }

        for (int i = 0; i < board.size(); i++) {
            cols[i] = {};
        }

        int n = 0;
        int off_cols = 0;
        int off_rows = 0;

        while (n < 9) {
            set<int> grid;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int c = (off_cols*3) + j; 
                    int r = (off_rows*3) + i;
                    
                    if (board[c][r] != '.') {
                        int val = board[c][r] - '0';
                        if (grid.count(val) || cols[c].count(val) || rows[r].count(val)) {
                            return false;
                        }
                        grid.insert(val);
                        cols[c].insert(val);
                        rows[r].insert(val);
                    }
                }
            }
            n++;
            if ((n % 3) == 0) {
                off_rows++;
                off_cols = 0;
            }
            else {
                off_cols++;
            }
        }

        return true;
    }
};
