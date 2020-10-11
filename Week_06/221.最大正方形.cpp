/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        if (!rowSize)
            return 0;
        int colSize = matrix[0].size();
        if (!colSize)
            return 0;
        
        int maxSize = 0;
        //初始化第一行第一列的dp状态为0
        vector<vector<int> > dp(rowSize+1,vector<int>(colSize+1,0));
        for (int i = 0;i<rowSize;i++){
            for (int j = 0;j<colSize;j++){
                if(matrix[i][j] == '1'){
                    dp[i+1][j+1] = min(dp[i][j],min(dp[i][j+1],dp[i+1][j]) )+ 1;
                    maxSize = max(maxSize,dp[i+1][j+1]);
                }
            }
        }
        return maxSize*maxSize;

    }
};
// @lc code=end

