/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string newStr = "#";
        for (int i = 0; i < s.size(); i++) {
            newStr.push_back(s[i]);
            newStr.push_back('#');
        }
        int n = newStr.size();
        int p[n], center = 0, maxRight = 0, maxCenter = 0, maxLen = 0;
        p[0] = 0;
        for (int i = 1; i < n; i++) {
            if (i >= maxRight) {
                int right = i;
                while (right + 1 < n && 2 * i - right > 0 && newStr[right+1] == newStr[2*i-right-1]) {
                    right++;
                }
                center = i;
                maxRight = right;
                p[i] = maxRight - i;
            }
            else if (maxRight - i < p[2*center-i]) {
                p[i] = maxRight - i;
            }
            else if (maxRight - i == p[2*center-i]) {
                int right = maxRight;
                while (right + 1 < n && 2 * i - right > 0 && newStr[right+1] == newStr[2*i-right-1]) {
                    right++;
                }
                center = i;
                maxRight = right;
                p[i] = maxRight - i;
            }
            else {
                p[i] = p[2*center-i];
            }
            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }
        return s.substr((maxCenter - maxLen) / 2, maxLen);
    }
};
// @lc code=end

