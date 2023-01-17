/*
 * @lc app=leetcode.cn id=2287 lang=java
 *
 * [2287] 重排字符形成目标字符串
 */

// @lc code=start
class Solution {
    public int rearrangeCharacters(String s, String target) {
        HashMap<Character, Integer> targetChar = new HashMap<Character, Integer>();
        HashMap<Character, Integer> sChar = new HashMap<Character, Integer>();
        for (int i = 0; i < target.length(); i++) {
            if (targetChar.containsKey(target.charAt(i))) {
                targetChar.replace(target.charAt(i), targetChar.get(target.charAt(i)) + 1);
            }
            else {
                targetChar.put(target.charAt(i), 1);
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (targetChar.containsKey(s.charAt(i))) {
                if (sChar.containsKey(s.charAt(i))) {
                    sChar.replace(s.charAt(i), sChar.get(s.charAt(i)) + 1);
                }
                else {
                    sChar.put(s.charAt(i), 1);
                }
            }
        }
        int min = Integer.MAX_VALUE;
        for (Character c : targetChar.keySet()) {
            if (!sChar.containsKey(c)) return 0;
            if (sChar.get(c) / targetChar.get(c) < min) min = sChar.get(c) / targetChar.get(c);
        }
        return min;
    }
}
// @lc code=end

