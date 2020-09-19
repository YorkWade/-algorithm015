/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
       int left = 0,right = x,ans = 0;
       while (left <= right)
       {
           int mid = left + (right -left)/2;
           if ((long long)mid * mid <= x){
                ans = mid;
                left = mid+1;
           }
           else
               right = mid-1;
       }
       return ans;
        
    }
};
// @lc code=end

