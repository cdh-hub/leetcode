/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 *
 * [2563] 统计公平数对的数目
 */

// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int p1 = 0, p2 = 0, p3 = 1;
        while (p3 < nums.size() && (long long)nums[p3] + nums[p3-1] < lower) {
            p3++;
        }
        p1 = p3-1;
        if (p3 < nums.size() && (long long)nums[p3] + nums[p1] <= upper) p2 = p3;
        else p2 = p1;
        while (p3 < nums.size()) {
            while (p1 > 0 && (long long)nums[p1-1] + nums[p3] >= lower) p1--;
            while (p2 < p3 && (long long)nums[p2] + nums[p3] <= upper) p2++;
            while (p2 > 0 && (long long)nums[p2-1] + nums[p3] > upper) p2--;
            ans += p2 - p1;
            p3++;
        }
        return ans;
    }
};
// @lc code=end

