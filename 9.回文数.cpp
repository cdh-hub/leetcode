/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        int len = 1, helper = 1;
        while (x / helper >= 10) {
            helper *= 10;
            len++;
        }
        int y = 0;
        for (int i = 0; i < len/2; i++) {
            y = y*10 + x % 10;
            x /= 10;
        }
        if (len & 1) y = y*10 + x%10;
        return x == y;
    }
};
// @lc code=end

