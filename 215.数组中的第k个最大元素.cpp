/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:
    int helper(vector<int>& nums, int l, int r, int k) {
        if (l == r) return nums[l];
        int mid = nums[l];
        int i = l, j = r;
        while (i < j) {
            while (i < j && nums[j] < mid) j--;
            nums[i] = nums[j];
            while (i < j && nums[i] >= mid) i++;
            nums[j] = nums[i];
        }
        nums[i] = mid;
        if (i - l + 1 == k) return nums[i];
        else if (i - l + 1 < k) return helper(nums, i+1, r, k - i + l - 1);
        else return helper(nums, l, i-1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return helper(nums, 0, nums.size()-1, k);
    }
};
// @lc code=end

