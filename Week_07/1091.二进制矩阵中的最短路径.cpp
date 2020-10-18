/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
int terminalX;
int terminalY;
class Solution {
public:
    class Pos{
    public:
        Pos(int x,int y,int distanceFromStart):x_(x),y_(y),distanceFromStart_(distanceFromStart){}
		
        int x_;
        int y_;
        int distanceFromStart_;
		friend bool operator <(const Pos& left, const Pos& right){
			return max(terminalX - left.x_, terminalY - left.y_) + left.distanceFromStart_ - (max(terminalX - right.x_, terminalY - right.y_) + right.distanceFromStart_) >= 0;
		}
    };

	
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty()) {
			return -1;
		}
        terminalX = grid.size();
        terminalY = grid[0].size();

		if (grid[0][0] == 1 || grid[terminalX - 1][terminalY - 1] == 1) {
			return -1;
		}
        if (terminalX == 1 && terminalY == 1) {
			return 1;
		}
        int directionMov[8][2] = {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}};
        vector<vector<int>> step (grid.size(),vector<int>(grid[0].size(),0));
        step[0][0] = 1;
        priority_queue<Pos> pq;
        pq.push(Pos(0,0,1));
        while (!pq.empty()){
            Pos cur = pq.top();
			pq.pop();
            for (int i = 0;i<8;i++){
                int nextX = cur.x_ + directionMov[i][0];
                int nextY = cur.y_ + directionMov[i][1];
                
                if (nextX>=0 && nextX<grid.size() 
                    && nextY >=0 && nextY<grid[0].size() 
                    && grid[nextX][nextY] == 0){
                    if (nextX == grid.size()-1 && nextY == grid[0].size()-1)
                        return step[cur.x_][cur.y_] +1;
                    // 没有到走过改点或者当前的路线更优
                    if (step[nextX][nextY] == 0 || step[nextX][nextY] > step[cur.x_][cur.y_]+1){
                        step[nextX][nextY] = step[cur.x_][cur.y_] + 1;
                        pq.push(Pos(nextX,nextY,step[cur.x_][cur.y_]+1));
                    }

                }
            }
        }
        return -1;
    }
};
// @lc code=end

