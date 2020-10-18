/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowSet[9][10] = {0};
        int colSet[9][10] = {0};
        int boxSet[9][10] = {0};

        for (int i = 0;i<9;i++){
            for (int j = 0;j<9;j++){
                if (board[i][j] == '.')
                    continue;
                int number = board[i][j]-'0';
                if (rowSet[i][number] || colSet[j][number] || boxSet[(i/3)*3+j/3][number])
                    return false;
                rowSet[i][number] = 1;
                colSet[j][number] = 1;
                boxSet[(i/3)*3+j/3][number] = 1;
            }
        }
        return true;
    }

    bool backtrace(vector<vector<char>> & board){
        for (int i = 0;i<board.size();i++){
            for (int j = 0;j<board[i].size();j++){
                if (board[i][j] == '.'){
                    for (int k = 1;k<=9;k++){
                        board[i][j] = '0'+k;
                        if (isValidSudoku(board)){

                            if (backtrace(board))
                                return true;
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrace(board);
    }
};
// @lc code=end

