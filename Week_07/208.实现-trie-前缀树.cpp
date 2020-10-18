/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() :isWord_(false){
        memset(next, 0, sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (int i = 0;i<word.size();i++){
            char ch = word[i]-'a';
            if (node->next[ch] == NULL)
                node->next[ch] = new Trie;
            node = node->next[ch];
        }
        node->isWord_ = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (int i = 0;i<word.size();i++){
            char ch = word[i]-'a';
            if (node->next[ch] == NULL)
                return false;
            node = node->next[ch];
        }
        return node->isWord_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (int i = 0;i<prefix.size();i++){
            char ch =prefix[i]-'a';
            if(node->next[ch] == NULL)
                return false;
            node = node->next[ch];
        }
        return true;
    }
private:
    Trie* next[26];
    bool isWord_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

