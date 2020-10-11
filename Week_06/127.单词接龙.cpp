/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end()),beginDict,endDict,*head,*tail;
        beginDict.insert(beginWord);
        endDict.insert(endWord);
        if (dict.count(endWord) == 0)
            return 0;
        int step = 2;
        while (!beginDict.empty() && !endDict.empty()){
            if (beginDict.size()<endDict.size()){
                head = &beginDict;
                tail = &endDict;
            }
            else {
                head = &endDict;
                tail = &beginDict;
            }

            unordered_set<string> tmp;
            for (auto it = head->begin();it != head->end();it++){
                string word = (*it);
                for (int j = 0;j<word.length();j++){
                    for (int k = 0;k < 26;k++){
                        char ch = word[j];
                        word[j] = 'a'+k;
                        if (tail->find(word) != tail->end())
                            return step;
                        if (dict.find(word) != dict.end()){
                            tmp.insert(word);
                            dict.erase(word);
                        }
                        word[j] = ch;
                    }
                }
            }
            step++;
            head->swap(tmp);
            
        }
        
        return 0;
    }
};
// @lc code=end

