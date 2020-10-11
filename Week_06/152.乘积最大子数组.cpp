/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        vector<int>maxDp(nums);
        vector<int>minDp(nums);
        for (int i = 1;i<nums.size();i++){
            maxDp[i] = max(maxDp[i-1]*nums[i],max(minDp[i-1]*nums[i],nums[i]) );
            minDp[i] = min(minDp[i-1]*nums[i],min(maxDp[i-1]*nums[i],nums[i]) );
        }
        return *max_element(maxDp.begin(),maxDp.end());
    }
};
// @lc code=end

