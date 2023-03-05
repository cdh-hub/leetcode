/*
 * @lc app=leetcode.cn id=982 lang=cpp
 *
 * [982] 按位与为零的三元组
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans = 0;
        int a[1<<16] = {0};
        for (int num1: nums) for (int num2: nums)
            a[num1&num2]++;
        for (int num: nums) {
            int x = num ^ ((1<<16)-1);
            for (int i = x; i != 0; i = (i-1)&x) {
                if ((num & i) == 0) {
                    ans += a[i];
                }
            }
            ans += a[0];
        }
        return ans;
    }
};
// @lc code=end

