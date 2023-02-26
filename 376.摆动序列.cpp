/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int dp1[n], dp2[n], left1[n], left2[n];
        for (int i = 0; i < n; i++) {
            left1[i] = left2[i] = -1;
        }
        stack<int> stk1, stk2;
        for (int i = 0; i < n; i++) {
            while(!stk1.empty() && nums[stk1.top()] <= nums[i]) stk1.pop();
            if (!stk1.empty()) left1[i] = stk1.top();
            stk1.push(i);
            while(!stk2.empty() && nums[stk2.top()] >= nums[i]) stk2.pop();
            if (!stk2.empty()) left2[i] = stk2.top();
            stk2.push(i);
        }
        dp1[0] = 1, dp2[0] = 1;
        for (int i = 1; i < n; i++) {
            dp1[i] = max(dp1[i-1], left2[i] == -1 ? 1 : (dp2[left2[i]]+1));
            dp2[i] = max(dp2[i-1], left1[i] == -1 ? 1 : (dp1[left1[i]]+1));
        }
        return max(dp1[n-1], dp2[n-1]);
    }
};
// @lc code=end

