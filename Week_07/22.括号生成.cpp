/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<string>&res,string curRes,int left,int right,int n){
        if(left == n && right == n){//仅仅right==n不可。left可能在回溯过程中超过n
            res.push_back(curRes);
            return;
        }
        
        if(left<=n)
            backtrace(res,curRes+"(",left+1,right,n);//left +1 不是left++,因为要恢复原来状态。
        if (right < left)//right < n条件不对。需要保证先有left才能有right。
            backtrace(res,curRes+")",left,right+1,n);
    }

    
    vector<string> generateParenthesis(int n) {
       vector<string> res;
       backtrace(res,"",0,0,n) ;
       return res;
    }
};
// @lc code=end

