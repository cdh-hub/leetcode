/*
 * @lc app=leetcode.cn id=1033 lang=cpp
 *
 * [1033] 移动石子直到连续
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(min(a, b), c);
        int z = max(max(a, b), c);
        int y = a + b + c - x - z;
        // int minimum_moves, maximum_moves;
        if (x + 1 == y && y + 1 == z) return {0, 0};
        if (y - x <= 2 || z - y <= 2) return {1, z-y-1+y-x-1};
        return {2, z-y-1+y-x-1};
    }
};
// @lc code=end

