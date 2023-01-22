/*
 * @lc app=leetcode.cn id=159 lang=cpp
 *
 * [159] 至多包含两个不同字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = 0, maxLen = 0, currLen = 0;
        unordered_set<char> set;
        while (j < s.size()) {
            switch (set.size()) {
                case 0:
                    set.insert(s[j]);
                    currLen++;
                    maxLen = max(maxLen, currLen);
                    j++;
                    break;
                case 1:
                    set.insert(s[j]);
                    currLen++;
                    maxLen = max(maxLen, currLen);
                    if (s[j] != s[j-1]) i = j;
                    j++;
                    break;
                case 2:
                    if (set.count(s[j])) {
                        currLen++;
                        maxLen = max(maxLen, currLen);
                        if (s[j] != s[j-1]) i = j;
                    }
                    else {
                        set.clear();
                        set.insert(s[i]);
                        set.insert(s[j]);
                        currLen = j - i + 1;
                        maxLen = max(maxLen, currLen);
                        i = j;
                    }
                    j++;
            }
        }
        return maxLen;
    }
};
// @lc code=end

