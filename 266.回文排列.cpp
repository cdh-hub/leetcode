/*
 * @lc app=leetcode.cn id=266 lang=cpp
 *
 * [266] 回文排列
 */

// @lc code=start
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        for (auto ch: s) map[ch]++;
        int cnt = 0;
        for (auto& [_, v]: map) {
            if (v % 2 != 0) cnt++;
        }
        return cnt <= 1;
    }
};
// @lc code=end

