/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins[amount+1];
        minCoins[0] = 0;
        for (int i = 1; i <= amount; i++) {
            minCoins[i] = -1;
            for (int c : coins) {
                if (i - c >= 0 && minCoins[i-c] >= 0) {                    
                    minCoins[i] = minCoins[i] == -1 ? minCoins[i-c]+1 : min(minCoins[i], minCoins[i-c]+1);
                } 
            }
        }
        return minCoins[amount];
    }
};
// @lc code=end

