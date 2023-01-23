/*
 * @lc app=leetcode.cn id=259 lang=cpp
 *
 * [259] 较小的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = i + 2;
            while (k < n && nums[i] + nums[j] + nums[k] < target) k++;
            if (k == i + 2) break;
            k--;
            while (j < k) {
                while (j < k && nums[i] + nums[j] + nums[k] < target) j++;
                j--;
                count += j - i;
                k--;
            }
            count += (k - i - 1) * (k - i) / 2;
        }
        return count;
    }
};
// @lc code=end

