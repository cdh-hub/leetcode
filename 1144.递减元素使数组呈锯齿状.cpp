/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        if (n == 1) return 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (i == n-1){
                    cnt1 += max(nums[i]-nums[i-1]+1, 0);
                }
                else {
                    cnt1 += max(max(nums[i]-nums[i-1]+1, nums[i]-nums[i+1]+1), 0);
                }
            }
            else {
                if (i == 0) {
                    cnt2 += max(nums[i]-nums[i+1]+1, 0);
                }
                else if (i == n-1){
                    cnt2 += max(nums[i]-nums[i-1]+1, 0);
                }
                else {
                    cnt2 += max(max(nums[i]-nums[i-1]+1, nums[i]-nums[i+1]+1), 0);
                }
            }
        }
        return min(cnt1, cnt2);
    }
};
// @lc code=end

