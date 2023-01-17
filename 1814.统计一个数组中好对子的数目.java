/*
 * @lc app=leetcode.cn id=1814 lang=java
 *
 * [1814] 统计一个数组中好对子的数目
 */

// @lc code=start
class Solution {
    private int rev(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
    public int countNicePairs(int[] nums) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            nums[i] = nums[i] - rev(nums[i]);
            if (hm.containsKey(nums[i])) hm.put(nums[i], hm.get(nums[i]) + 1);
            else hm.put(nums[i], 1);
        }
        long cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            cnt += hm.get(nums[i]) - 1;
        }
        cnt /= 2;
        cnt %= 1e9 + 7;
        return (int)cnt;
    }
}
// @lc code=end

