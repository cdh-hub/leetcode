/*
 * @lc app=leetcode.cn id=1824 lang=java
 *
 * [1824] 最少侧跳次数
 */

// @lc code=start
class Solution {
    public int minSideJumps(int[] obstacles) {
        int cur = 2, jump = 0;
        boolean jumped = false;
        for (int i = 0; i < obstacles.length - 1; i++) {
            if (!jumped && obstacles[i+1] == cur) {
                jump++;
                jumped = true;
                if (obstacles[i] != 0) {
                    cur = 6 - cur - obstacles[i];
                    jumped = false;
                }
            }
            if (jumped && obstacles[i+1] != 0 && obstacles[i+1] != cur) {
                cur = 6 - cur - obstacles[i+1];
                jumped = false;
            }
        }
        return jump;
    }
}
// @lc code=end

