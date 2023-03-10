/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */

// @lc code=start
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int preSum[n+1];
        preSum[0] = 0;
        for (int i = 1; i <= n; i++) {
            preSum[i] = (preSum[i-1] + nums[i-1]) % p;
        }
        unordered_map<int, int> mp;
        mp[0] = 0;
        int ans = n;
        for (int i = 1; i <= n; i++) {
            mp[preSum[i]] = i;
            if (mp.count((preSum[i]-preSum[n]+p)%p)) ans = min(ans, i-mp[(preSum[i]-preSum[n]+p)%p]);
        }
        return ans == n ? -1: ans;
    }
};
// @lc code=end

