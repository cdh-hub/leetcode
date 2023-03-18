/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int q: queries) {
            int i = 0, sum = 0;
            while (i < nums.size() && sum + nums[i] <= q) {
                sum += nums[i];
                i++;
            }
            ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

