/*
 * @lc app=leetcode.cn id=2325 lang=java
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution {
    public String decodeMessage(String key, String message) {
        char[] a = new char[26];
        boolean[] record = new boolean[26];
        for (int i = 0; i < 26; i++) {
            record[i] = false;
        }
        char ch = 'a';
        for (int i = 0; i < key.length(); i++) {
            if (key.charAt(i) != ' ' && !record[key.charAt(i)-'a']) {
                record[key.charAt(i)-'a'] = true;
                a[key.charAt(i)-'a'] = ch;
                ch++;
                if (ch > 'z') break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < message.length(); i++) {
            if (message.charAt(i) == ' ') sb.append(' ');
            else sb.append(a[message.charAt(i)-'a']);
        }
        return sb.toString();
    }
}
// @lc code=end

