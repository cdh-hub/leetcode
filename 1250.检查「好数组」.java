/*
 * @lc app=leetcode.cn id=1250 lang=java
 *
 * [1250] 检查「好数组」
 */

// @lc code=start
class Solution {
    public boolean isGoodArray(int[] nums) {
        int a = nums[0];
        for (int i = 1; i < nums.length; i++) {
            a = gcd(a, nums[i]);
            if (a == 1) return true;
        }
        return a == 1;
    }
    private int gcd(int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (a == 0) return b;
        return gcd(b % a, a);
    }
}
// @lc code=end

