/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        std::vector<int> results;
        std::map<int,int> cache;
        for ( int i = 0; i<nums.size(); i++ ) {
            std::map<int,int>::iterator it = cache.find(target - nums[i]);
            if ( it == cache.end()) 
                cache[nums[i]] = i;
            else
            {
                results.push_back(it->second);
                results.push_back(i);
                return results;
            }
        }
        return results;
    }
};
// @lc code=end

