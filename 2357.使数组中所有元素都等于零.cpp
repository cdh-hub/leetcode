/*
 * @lc app=leetcode.cn id=2357 lang=cpp
 *
 * [2357] 使数组中所有元素都等于零
 */

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int a[101] = {0};
        for (int num: nums) ++a[num];
        int ans = 0;
        for (int i = 1; i <= 100; i++) {
            if (a[i]) ans++;
        }
        return ans;
    }
};
// @lc code=end

