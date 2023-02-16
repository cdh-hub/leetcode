/*
 * @lc app=leetcode.cn id=2515 lang=cpp
 *
 * [2515] 到目标字符串的最短距离
 */

// @lc code=start
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        for (int i = 0; i <= words.size() / 2; i++) {
            if (words[(startIndex+i)%words.size()] == target) return i;
            if (words[(startIndex-i+words.size())%words.size()] == target) return i;
        }
        return -1;
    }
};
// @lc code=end

