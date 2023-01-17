/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int sum = 0;
        while (i < n && i < k && nums[i] < 0) nums[i] = -nums[i], i++;
        if (i < k) {
            sort(nums.begin(), nums.end());
            if ((k - i) & 1) nums[0] = -nums[0];
        }
        for (i = 0; i < n; i++) sum += nums[i];
        return sum;
    }
};
// @lc code=end

