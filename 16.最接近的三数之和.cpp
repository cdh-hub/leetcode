/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2], diff = abs(ans - target);
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                int l = j+1, r = n-1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    int sum = nums[mid] + nums[i] + nums[j];
                    if (sum == target) return target;
                    else if (sum < target) l = mid + 1;
                    else r = mid - 1;
                }
                int diff1 = INT_MAX, diff2 = INT_MAX;
                if (r > j) diff1 = nums[i] + nums[j] + nums[r] - target;
                if (l < n) diff2 = nums[i] + nums[j] + nums[l] - target;
                if (min(abs(diff1), abs(diff2)) < diff) {
                    diff = min(abs(diff1), abs(diff2));
                    ans = target + (abs(diff1) < abs(diff2) ? diff1 : diff2);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

