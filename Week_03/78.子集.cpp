/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    void backtrace(vector<vector<int>>&res,vector<int>&cur,int start,vector<int>&nums)
    {

        res.push_back(cur);
        if (start == nums.size())
        {
            return;
        }
        
        for (int i = start;i<nums.size();i++)
        {
            cur.push_back(nums[i]);
            backtrace(res,cur,i+1,nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> cur;
        backtrace(res,cur,0,nums);
        return res;
    }
};
// @lc code=end

