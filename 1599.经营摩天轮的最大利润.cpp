/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int profit = 0, times = -1, left = 0;
        for (int i = 0; i < customers.size() || left; i++) {
            if (i < customers.size()) left += customers[i];
            int num;
            if (left >= 4) {
                left -= 4;
                num = 4;
            }
            else {
                num = left;
                left = 0;
            }
            if (profit + num*boardingCost - runningCost > profit) {
                profit += num*boardingCost - runningCost;
                times = i + 1;
            }
        }
        return times;
    }
};
// @lc code=end

