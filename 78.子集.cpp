/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtrack(vector<int>& nums, int index) {
        ans.push_back(cur);
        for (int i = index; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(nums, i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
// @lc code=end

