/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char, int> map;
        int left = -1;
        for (int i = 0; i < s.size(); i++) {
            if (map.count(s[i])) left = max(left, map[s[i]]);
            maxLen = max(maxLen, i - left);
            map[s[i]] = i;
        }
        return maxLen;
    }
};
// @lc code=end

