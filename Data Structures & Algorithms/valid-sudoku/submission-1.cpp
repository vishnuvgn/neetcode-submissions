class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check
        for (int r = 0; r < 9; ++r) {
            std::unordered_set<char> seen;
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] != '.') {
                    if (seen.find(board[r][c]) != seen.end()) return false;
                    else (seen.insert(board[r][c]));
                }
            }
        }

        // col check
        for (int c = 0; c < 9; ++c) {
            std::unordered_set<char> seen;
            for (int r = 0; r < 9; ++r) {
                if (board[r][c] != '.') {
                    if (seen.find(board[r][c]) != seen.end()) return false;
                    else (seen.insert(board[r][c]));
                }
            }
        }

        // box check
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                std::unordered_set<char> seen;
                for (int r = i; r < i + 3; ++r) {
                    for (int c = j; c < j + 3; ++c) {
                        if (board[r][c] != '.') {
                            if (seen.find(board[r][c]) != seen.end()) return false;
                            else (seen.insert(board[r][c]));
                        }
                    }
                }
            }
        }
        return true;
    }
};
