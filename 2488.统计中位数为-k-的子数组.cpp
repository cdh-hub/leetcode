/*
 * @lc app=leetcode.cn id=2488 lang=cpp
 *
 * [2488] 统计中位数为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++;
        bool tag = true;
        int pre = 0, ans = 0;
        for (int num: nums) {
            if (num == k) tag = false;
            else pre += num > k ? 1 : -1;
            if (tag) mp[pre]++;
            else ans += mp[pre-1] + mp[pre];
        }
        return ans;
    }
};
// @lc code=end

