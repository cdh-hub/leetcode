/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        auto left = nums.begin();
        auto right = nums.end();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i-1]) left++; 
            else break;
        }
        if (right-left == 1) return 0;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= nums[i+1]) right--;
            else break;
        }
        int maxE = *max_element(left, right), minE = *min_element(left, right);
        int l = 0, r = n-1;
        while (nums[l] <= minE) l++;
        while (nums[r] >= maxE) r--;
        return r - l + 1;
    }
};
// @lc code=end

