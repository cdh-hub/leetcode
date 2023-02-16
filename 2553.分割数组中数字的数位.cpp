/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 *
 * [2553] 分割数组中数字的数位
 */

// @lc code=start
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> stk;
        for (auto n: nums) {
            if (n == 0) ans.push_back(0);
            else {
                while (n) {
                    stk.push(n % 10);
                    n /= 10;
                }
                while (!stk.empty()) {
                    ans.push_back(stk.top());
                    stk.pop();
                }
            }
        }
        return ans;
    }
};
// @lc code=end

