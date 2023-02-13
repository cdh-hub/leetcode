/*
 * @lc app=leetcode.cn id=1124 lang=java
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
class Solution {
    public int longestWPI(int[] hours) {
        int[] pre = new int[hours.length+1];
        pre[0] = 0;
        for (int i = 1; i <= hours.length; i++) {
            pre[i] = pre[i-1] + (hours[i-1] > 8 ? 1 : -1);
        }
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < pre.length; i++) {
            if (stk.isEmpty() || pre[stk.peek()] > pre[i]) stk.push(i);
        }
        int ans = 0;
        for (int i = pre.length-1; i > 0; i--) {
            if (!stk.isEmpty() && stk.peek().equals(i)) {
                stk.pop();
            }
            while (!stk.isEmpty() && pre[i] > pre[stk.peek()]) {
                ans = Math.max(ans, i - stk.peek());
                stk.pop();
            };
        }
        return ans;
    }
}
// @lc code=end

