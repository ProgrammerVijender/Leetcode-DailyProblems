class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // check row and col
        for (int k = 0; k < 9; k++) {
            if (board[row][k] == c) return false;
            if (board[k][col] == c) return false;
        }

        // check 3x3 sub-box
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for (int i = sr; i < sr + 3; i++) {
            for (int j = sc; j < sc + 3; j++) {
                if (board[i][j] == c) return false;
            }
        }

        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (backtrack(board)) return true;
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // if no number works
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};