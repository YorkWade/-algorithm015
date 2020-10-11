/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int res = 0,minPrice = prices[0];
        for (int i = 1;i<prices.size();i++){
                minPrice = min(minPrice,prices[i]);
                res = max(res,prices[i]-minPrice);
        }
        return res;
    }
};
// @lc code=end

