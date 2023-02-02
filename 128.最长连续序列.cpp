/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num: nums) {
            set.insert(num);
        }
        int longest = 0;
        for (auto num: nums) {
            if (set.count(num-1)) continue;
            int count = 1;
            while (set.count(num+1)) {
                num++;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};
// @lc code=end

