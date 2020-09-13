/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    void backtrace(vector<vector<int>>&res,vector<int>& cur,vector<bool>&used,vector<int> & nums){
        if (cur.size() == nums.size()){
            res.push_back(cur);
            return ;
        }

        for (int i = 0;i<nums.size();i++) {
            if (used[i])
                continue;
            cur.push_back(nums[i]);
            used[i] = true;
            backtrace(res,cur,used,nums);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>res;
        vector<int> cur;
        vector<bool> used;
        used.resize(nums.size(),false);
        backtrace(res,cur,used,nums);
        return res;
    }
};
// @lc code=end

