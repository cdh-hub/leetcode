/*
 * @lc app=leetcode.cn id=2299 lang=java
 *
 * [2299] 强密码检验器 II
 */

// @lc code=start
class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) return false;
        boolean lowercase = false, uppercase = false, hasnum = false, hasspecial = false;
        String s = "!@#$%^&*()-+";
        for (int i = 0; i < password.length(); i++) {
            if (password.charAt(i) >= 'a' && password.charAt(i) <= 'z') lowercase = true;
            if (password.charAt(i) >= 'A' && password.charAt(i) <= 'Z') uppercase = true;
            if (password.charAt(i) >= '0' && password.charAt(i) <= '9') hasnum = true;
            if (s.contains(password.charAt(i)+"")) hasspecial = true;
            if (i > 0 && password.charAt(i) == password.charAt(i-1)) return false;
        }
        return lowercase && uppercase && hasnum && hasspecial;
    }
}
// @lc code=end

