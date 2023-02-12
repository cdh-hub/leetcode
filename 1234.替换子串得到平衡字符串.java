/*
 * @lc app=leetcode.cn id=1234 lang=java
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
class Solution {
    private int n;
    private boolean check(int[] count) {
        for (int i = 0; i < 4; i++) {
            if (count[i] > n / 4) return false;
        }
        return true;
    }
    public int balancedString(String s) {
        n = s.length();
        int count[] = new int[4];
        HashMap<Character, Integer> hm = new HashMap<>();
        hm.put('Q', 0); hm.put('W', 1); hm.put('E', 2); hm.put('R', 3);
        for (int i = 0; i < 4; i++) count[i] = 0;
        for (int i = 0; i < n; i++) count[hm.get(s.charAt(i))]++;
        if (check(count)) return 0;
        int left = 0, right = 0;
        while (right < s.length() && !check(count)) {
            count[hm.get(s.charAt(right))]--;
            right++;
        }
        while (left < right && check(count)) {
            count[hm.get(s.charAt(left))]++;
            left++;
        }
        int minLen = right - left + 1;
        while (right < s.length()) {
            count[hm.get(s.charAt(right))]--;
            right++;
            while (left < right && check(count)) {
                count[hm.get(s.charAt(left))]++;
                left++;
            }
            minLen = Math.min(minLen, right - left + 1);
        }
        return minLen;
    }
}
// @lc code=end

