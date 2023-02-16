/*
 * @lc app=leetcode.cn id=2552 lang=cpp
 *
 * [2552] 统计上升四元组
 */

// @lc code=start
int low[4010][4010];
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans = 0;
        for (int i = 1; i <= nums.size(); i++) {
            low[0][i] = 0;
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= nums.size(); j++) {
                low[i][j] = low[i-1][j] + (nums[i-1] < j ? 1 : 0);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    ans += (long long)low[i][nums[j]] * (nums.size() - nums[i] - (j - low[j][nums[i]] - 1));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

