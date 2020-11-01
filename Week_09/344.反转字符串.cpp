/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int left = 0,right = s.size()-1;left<=right;left++,right--){
            swap(s[left],s[right]);
        }
    }
};
// @lc code=end

