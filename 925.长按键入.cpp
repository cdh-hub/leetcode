/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1 = name.size();
        int n2 = typed.size();
        int i = 0, j = 0;
        while (j < n2) {
            if (i < n1 && name[i] == typed[j]) i++, j++;
            else if (j == 0 || typed[j] != typed[j-1]) return false;
            else {
                while (j < n2 && typed[j] == typed[j-1]) j++;
                if (i >= n1) return j >= n2;
            }
        }
        return i >= n1;
    }
};
// @lc code=end

