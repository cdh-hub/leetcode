/*
 * @lc app=leetcode.cn id=2520 lang=cpp
 *
 * [2520] 统计能整除数字的位数
 */

// @lc code=start
class Solution {
public:
    int countDigits(int num) {
        int i = 0, count = 0, n = num;
        while (n) {
            if (num % (n % 10) == 0) count++;
            n /= 10;
            i++;
        }
        return count;
    }
};
// @lc code=end

