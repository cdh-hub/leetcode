/*
 * @lc app=leetcode.cn id=1664 lang=java
 *
 * [1664] 生成平衡数组的方案数
 */

// @lc code=start
class Solution {
    public int waysToMakeFair(int[] nums) {
        int[] leftOddSum = new int[nums.length];
        int[] leftEvenSum = new int[nums.length];
        leftOddSum[0] = 0;
        leftEvenSum[0] = 0;
        for (int i = 1; i < nums.length; i++) {
            leftOddSum[i] = leftEvenSum[i-1] + nums[i-1];
            leftEvenSum[i] = leftOddSum[i-1];
        }
        int count = 0;
        int rightEvenSum = 0;
        int rightOddSum = 0;
        if (leftEvenSum[nums.length-1]+rightOddSum == leftOddSum[nums.length-1]+rightEvenSum) count++;
        for (int i = nums.length - 2; i >= 0; i--) {
            int tmp = rightEvenSum + nums[i+1];
            rightEvenSum = rightOddSum;
            rightOddSum = tmp;
            if (leftEvenSum[i] + rightOddSum == leftOddSum[i] + rightEvenSum) count++;
        }
        return count;
    }
}
// @lc code=end

