/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int dp[n];
        int left[n];
        int maxLen = 0, maxIndex = -1;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            left[i] = -1;
            int j = i-1;
            for (; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        left[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }
        vector<int> ans;
        while (maxIndex != -1) {
            ans.push_back(nums[maxIndex]);
            maxIndex = left[maxIndex];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

