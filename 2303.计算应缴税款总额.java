/*
 * @lc app=leetcode.cn id=2303 lang=java
 *
 * [2303] 计算应缴税款总额
 */

// @lc code=start
class Solution {
    public double calculateTax(int[][] brackets, int income) {
        int pre = 0;
        double sum = 0;
        for (int i = 0; i < brackets.length; i++) {
            if (income >= brackets[i][0]) {
                sum += 0.01 * (brackets[i][0] - pre) * brackets[i][1];
                pre = brackets[i][0];
            }
            else {
                sum += 0.01 * (income - pre) * brackets[i][1];
                break;
            }
        }
        return sum;
    }
}
// @lc code=end

