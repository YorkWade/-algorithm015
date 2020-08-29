/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastDiff = 0;
       for (int i = 1; i < nums.size(); i++)
       {
           if (nums[i] != nums[lastDiff] )
           {
               nums[++lastDiff] = nums[i];
           }
           
       }
       return lastDiff+1;
    }
};
// @lc code=end

