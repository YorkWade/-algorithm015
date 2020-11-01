/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {

        for (int wordStart = 0;wordStart<s.size();wordStart++){
            if (s[wordStart] == ' ')
                continue;
            int wordIndex = wordStart;
            while ( wordIndex < s.size() && s[wordIndex] != ' ' ) wordIndex++;
            reverse(s.begin()+  wordStart ,s.begin()+wordIndex);
            wordStart = wordIndex;
        }
        return s;
    }
};
// @lc code=end

