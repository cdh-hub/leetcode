/*
 * @lc app=leetcode.cn id=487 lang=cpp
 *
 * [487] 最大连续1的个数 II
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zero = 0, maxOne = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zero++;
            while (zero > 1) {
                if (nums[left] == 0) zero--;
                left++;
            }
            maxOne = max(maxOne, right - left + 1);
        }
        return maxOne;
    }
};
// @lc code=end

