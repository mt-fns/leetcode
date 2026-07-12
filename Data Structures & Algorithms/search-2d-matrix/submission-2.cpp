class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int N_COLS = matrix[0].size();
        const int N_ROWS = matrix.size();
        int l = 0;
        int r = N_COLS*N_ROWS-1;

        // [0, 1]
        // [2, 3]
        // [4, 5]
        // [0, 1, 2, 3, 4, 5]
        // mid = 2 -> n_row = mid / cols -> 1 
        // m       -> n_col = mid % cols -> 0

        // mid = 3 -> n_row = 3/2 -> 1
        //         -> n_col = mid % cols -> 1
        while (l <= r) {
            int mid = (l+r)/2;
            int i_row = mid / N_COLS;
            int i_col = mid % N_COLS;

            if (matrix[i_row][i_col] == target) {
                return true;
            }

            if (matrix[i_row][i_col] < target) {
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
