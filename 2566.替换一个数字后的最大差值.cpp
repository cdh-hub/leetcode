/*
 * @lc app=leetcode.cn id=2566 lang=cpp
 *
 * [2566] 替换一个数字后的最大差值
 */

// @lc code=start
class Solution {
public:
    int minMaxDifference(int num) {
        int bit1 = 9, bit2 = 0;
        int num2 = num;
        stack<int> stk;
        while (num2 > 0) {
            if (num2 % 10 != 9) bit1 = num2 % 10;
            stk.push(num2 % 10);
            num2 /= 10;
        }
        bit2 = stk.top();
        int a = 0, b = 0;
        while (!stk.empty()) {
            a = a * 10 + (stk.top() == bit1 ? 9 : stk.top());
            b = b * 10 + (stk.top() == bit2 ? 0 : stk.top());
            stk.pop();
        }
        return a - b;
    }
};
// @lc code=end

