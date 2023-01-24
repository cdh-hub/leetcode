/*
 * @lc app=leetcode.cn id=1828 lang=java
 *
 * [1828] 统计一个圆中点的数目
 */

// @lc code=start
class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = 0;
            for (int j = 0; j < points.length; j++) {
                int x2 = (queries[i][0] - points[j][0]) * (queries[i][0] - points[j][0]);
                int y2 = (queries[i][1] - points[j][1]) * (queries[i][1] - points[j][1]);
                int r2 = queries[i][2] * queries[i][2];
                if (x2 + y2 <= r2) ans[i]++;
            }
        }
        return ans;
    }
}
// @lc code=end

