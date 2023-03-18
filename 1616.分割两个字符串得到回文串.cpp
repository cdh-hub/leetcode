/*
 * @lc app=leetcode.cn id=1616 lang=cpp
 *
 * [1616] 分割两个字符串得到回文串
 */

// @lc code=start
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int j1 = (a.size()-1)/2, i1 = a.size()/2;
        int i2 = i1, j2 = j1;
        while (i1 > 0 && a[i1-1] == a[j1+1]) {
            i1--; j1++;
        }
        while (i2 > 0 && b[i2-1] == b[j2+1]) {
            i2--; j2++;
        }
        bool tag1 = false, tag2 = false;
        int i = 0, j = a.size()-1;
        while (i < i1 && i < i2) {
            if (a[i] != b[j]) tag1 = true;
            if (b[i] != a[j]) tag2 = true;
            if (tag1 && tag2) return false;
            i++; j--;
        }
        return true;
    }
};
// @lc code=end

