/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void dfs(int row,int col,int rn,int cn,vector<vector<char>>& grid){
        
        grid[row][col] = '0';
        if (row -1 >= 0 && grid[row-1][col] == '1') dfs(row-1,col,rn,cn,grid);
        if (row +1 < rn && grid[row+1][col] == '1') dfs(row+1,col,rn,cn,grid);
        if (col -1 >= 0 && grid[row][col-1] == '1') dfs(row,col-1,rn,cn,grid);
        if (col +1 < cn && grid[row][col+1] == '1') dfs(row,col+1,rn,cn,grid);
    }
    int numIslands(vector<vector<char>>& grid) {

       int rn = grid.size();
       int cn = 0;
       if (!rn) return 0; 
       cn = grid[0].size();
       int numsIslands = 0;
       for (int i = 0;i<rn;i++){
           for (int j = 0;j<cn;j++){
               if (grid[i][j] == '1'){
                    numsIslands++;
                    dfs(i,j,rn,cn,grid);
               }
          }
       }
       return numsIslands;
    }
};
// @lc code=end

