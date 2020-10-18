/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class Solution {
public:
    class UnionFind{
    public:
        UnionFind(int n):parent(n,0),count_(n){
            for (int i = 0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int i){
            while (parent[i] != i){
                parent[i] = parent[parent[i]];//路径压缩,当前节点的父节点，指向爷爷节点。
                i = parent[i];//顺腾摸瓜找父节点
            }
            return i;
        }
        
        void unionParent(int p,int q){
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;
            //不同树，需要合并，并且计数count减一
            parent[rootP] = rootQ;
            count_--;
        }

        vector<int> parent;
        int count_;
    };
    int findCircleNum(vector<vector<int>>& M) {
        UnionFind uf(M.size());//i和j对称，所以只需要一边的维度，但需要遍历每个点
        for (int i = 0;i<M.size();i++){
            for (int j = 0;j<M[i].size();j++){
                if (M[i][j] == 1)
                    uf.unionParent(i,j);
            }
        }
        return uf.count_;
    }
};
// @lc code=end

