/*
 * @lc app=leetcode.cn id=2293 lang=java
 *
 * [2293] 极大极小游戏
 */

// @lc code=start
class Solution {
    private int getMinVal(int[] nums, int l, int r) {
        if (l == r) return nums[l];
        return Math.min(getMinVal(nums, l, (l+r)/2), getMaxVal(nums, (l+r)/2+1, r));
    }
    private int getMaxVal(int[] nums, int l, int r) {
        if (l == r) return nums[l];
        return Math.max(getMinVal(nums, l, (l+r)/2), getMaxVal(nums, (l+r)/2+1, r));
    }
    public int minMaxGame(int[] nums) {
        return getMinVal(nums, 0, nums.length-1);
    }
}
// @lc code=end

