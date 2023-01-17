/*
 * @lc app=leetcode.cn id=1819 lang=java
 *
 * [1819] 序列中不同最大公约数的数目
 */

// @lc code=start
class Solution {
    private int gcd(int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (a == 0) return b;
        else return gcd(b % a, a);
    }
    public int countDifferentSubsequenceGCDs(int[] nums) {
        int maxInNums = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > maxInNums) maxInNums = nums[i];
        }
        boolean hasNum[] = new boolean[maxInNums+1];
        for (int i = 0; i < nums.length; i++) {
            hasNum[nums[i]] = true;
        }
        int count = 0;
        for (int i = 1; i <= maxInNums; i++) {
            int g = 0;
            for (int j = i; j <= maxInNums && g != i; j+=i) {
                if (hasNum[j]) {
                    g = gcd(g, j);
                }
            }
            if (g == i) count++;
        }
        return count;
    }
}
// @lc code=end

