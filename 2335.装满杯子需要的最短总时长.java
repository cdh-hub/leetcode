import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=2335 lang=java
 *
 * [2335] 装满杯子需要的最短总时长
 */

// @lc code=start
class Solution {
    public int fillCups(int[] amount) {
        Arrays.sort(amount);
        int m = amount[0], n = amount[1], o = amount[2];        
        return m + n <= o ? o : (m+n+o+1)/2;
    }
}
// @lc code=end

