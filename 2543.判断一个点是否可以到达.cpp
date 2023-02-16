/*
 * @lc app=leetcode.cn id=2543 lang=cpp
 *
 * [2543] 判断一个点是否可以到达
 */

// @lc code=start
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int a = __gcd(targetX, targetY);
        while ((a & 1) == 0) a = a >> 1;
        return a == 1;
    }
};
// @lc code=end

