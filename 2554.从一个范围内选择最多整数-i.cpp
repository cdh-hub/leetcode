/*
 * @lc app=leetcode.cn id=2554 lang=cpp
 *
 * [2554] 从一个范围内选择最多整数 I
 */

// @lc code=start
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> ban;
        for (auto b: banned) {
            ban.insert(b);
        }
        int count = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            if (ban.count(i)) continue;
            sum += i;
            if (sum > maxSum) break;
            count++;
        }
        return count;
    }
};
// @lc code=end

