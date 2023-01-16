/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution {
public:
    string customSortString(string order, string s) {
        int index = 0;
        for (auto c: order) {
            for (int i = index; i < s.size(); i++) {
                if (s[i] == c) swap(s[i], s[index++]);
            }
        }
        return s;
    }
};
// @lc code=end

