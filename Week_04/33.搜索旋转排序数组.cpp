// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem33.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        if (n==1) return target == nums[0]?0:-1;
        int left = 0;
        int right =n-1;
        
        while (left<=right)
        {
            int mid = left + ((right - left)>>1);
            if (target == nums[mid])
                return  mid;

            if (nums[left]<=nums[mid]){//left ordered
                if (nums[left]<=target && target<nums[mid])
                    right = mid-1;
                else 
                    left = mid+1;
            }
            else {// right ordered
                if (nums[mid]<target && target<=nums[right])
                    left = mid +1;
                else 
                    right = mid-1;

            }
        }
        return -1; 

    }
};
// @lc code=end

