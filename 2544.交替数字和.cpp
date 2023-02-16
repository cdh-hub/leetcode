/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */

// @lc code=start
class Solution {
public:
    int alternateDigitSum(int n) {
        bool tag = false;
        int sum = 0;
        while (n) {
            if (tag) {
                sum += n % 10;
                tag = false;
            }
            else {
                sum -= n % 10;
                tag = true;
            }
            n /= 10;
        }
        if (tag) sum = -sum;
        return sum;
    }
};
// @lc code=end

