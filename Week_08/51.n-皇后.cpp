/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        if(n<1)
            return vector<vector<string>>();
        size_ = n;
        mask_ = ( 1<<n ) - 1;

        vector<int> curRes(n,0);
        backtrace(0,0,0,0,curRes);
        return generateAns();
    }

    void backtrace(int row,int col,int pie,int na,vector<int>& curRes){
        if (row >= size_){
            res_.push_back(curRes);
            return;
        }

        int bitRow = mask_&~(col | pie | na);
        while (bitRow){
            int bit = bitRow & (-bitRow) ;//获取最右边的1
            curRes[row] = bit;
            backtrace(row+1 ,(col | bit) ,(pie|bit)<<1,(na|bit)>>1 ,curRes);
            bitRow ^= bit; //清除最右边的1
        }
    }

    vector<vector<string>> generateAns(){
        vector<vector<string> > ans(res_.size(),vector<string> (size_,string(size_,'.') ) );
        for (int i = 0;i<res_.size();i++){
            for (int j = 0;j<size_; j++){
                int count = 0;
                int oneRes = res_[i][j];
                while (oneRes){
                    oneRes>>=1;
                    count++;
                }
                ans[i][j][size_-count] = 'Q';
            }
        }
        return ans;
    }

    int size_;
    int mask_;
    vector<vector<int> > res_;
};
// @lc code=end

