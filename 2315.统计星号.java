/*
 * @lc app=leetcode.cn id=2315 lang=java
 *
 * [2315] 统计星号
 */

// @lc code=start
class Solution {
    public int countAsterisks(String s) {
        int count = 0;
        boolean tag = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '|') {
                tag = !tag;
                continue;
            }
            if (!tag && s.charAt(i) == '*') count++;
        }
        return count;
    }
}
// @lc code=end

