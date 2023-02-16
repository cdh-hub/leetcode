/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 *
 * [2537] 统计好子数组的数目
 */

// @lc code=start
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size(), left = 0;
        long long ans = 0, curSum = 0;
        unordered_map<int, int> map;
        for (int right = 0; right < n; right++) {
            curSum += map[nums[right]];
            map[nums[right]]++;
            while (curSum >= k) {
                map[nums[left]]--;
                curSum -= map[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

