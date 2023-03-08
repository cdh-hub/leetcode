/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int cnt = 0;
        for (char ch: s) cnt += 1 - ch + 'a';
        int ans = cnt;
        for (char ch: s) ans = min(ans, cnt += ((ch - 'a') << 1) - 1);
        return ans;
    }
};
// @lc code=end

