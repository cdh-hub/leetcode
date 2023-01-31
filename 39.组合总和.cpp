/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> cur;
    void backtrack(vector<int>& candidates, int target, int pos) {
        if (target == 0) ans.push_back(cur);
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                cur.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

