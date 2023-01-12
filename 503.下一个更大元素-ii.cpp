/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vec(nums.size(), -1);
        stack<int> stk;
        int n = 2;
        while (n--)
        for (int i = 0; i < nums.size(); ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                vec[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        return vec;
    }
};
// @lc code=end

