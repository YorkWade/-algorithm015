/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int>>();
        
        vector<vector<int>>res;
        queue<TreeNode*> curLevelQueue;
        curLevelQueue.push(root);
        while (!curLevelQueue.empty())
        {
            
            vector<int> levelRes;
            int size = curLevelQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = curLevelQueue.front();
                levelRes.push_back(curNode->val) ;
                curLevelQueue.pop();   

                if(curNode->left)curLevelQueue.push(curNode->left);
                if(curNode->right)curLevelQueue.push(curNode->right);
            }
            
            res.push_back(levelRes);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

