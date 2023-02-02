/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int minNum = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            minNum = min(minNum, prices[i]);
            mp = max(mp, prices[i] - minNum);
        }
        return mp;
    }
};
// @lc code=end

