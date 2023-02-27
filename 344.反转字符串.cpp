/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int m = n / 2;
        for (int i = 0; i < m; i++) {
            swap(s[i], s[n-i-1]);
        }
    }
};
// @lc code=end

