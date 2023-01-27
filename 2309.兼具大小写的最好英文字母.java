/*
 * @lc app=leetcode.cn id=2309 lang=java
 *
 * [2309] 兼具大小写的最好英文字母
 */

// @lc code=start
class Solution {
    public String greatestLetter(String s) {
        HashSet<Character> set = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            set.add(s.charAt(i));
        }
        for (char ch = 'Z'; ch >= 'A'; ch--) {
            if (set.contains(ch) && set.contains((char)('a'+(ch-'A')))) {
                return String.valueOf(ch);
                }
        }
        return "";
    }
}
// @lc code=end

