/*
 * @lc app=leetcode.cn id=1663 lang=java
 *
 * [1663] 具有给定数值的最小字符串
 */

// @lc code=start
class Solution {
    public String getSmallestString(int n, int k) {
        StringBuilder sb = new StringBuilder();
        for (int i = n-1; i >= 0; i--) {
            int num = Math.min(k - i, 26);
            sb.append((char)('a' + num - 1));
            k -= num;
        }
        return sb.reverse().toString();
    }
}
// @lc code=end

