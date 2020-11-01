/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        res_ = 0;
        mask_ = (1<<n)-1;
        backtrace(n,0,0,0,0);
        return res_;
    }

    void backtrace(int n,int row,int col,int pie,int na){
        if (row >= n){
            res_++;
            return;
        }

        int  oneRowBit = mask_ & ~(col | pie | na);
        while (oneRowBit){
            int pick = oneRowBit & (-oneRowBit);
            backtrace(n,row+1,col | pick ,(pie | pick)<<1,(na | pick)>>1);
            oneRowBit ^= pick;
        }
    }

    int mask_;
    int res_;

};
// @lc code=end

