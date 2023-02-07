/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool check(vector<int>& nums, int maxValue) {
        long long cur = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > maxValue) cur += nums[i] - maxValue;
            else cur = max(0LL, cur - (maxValue - nums[i]));
        }
        return cur == 0;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end()), 
        r = *max_element(nums.begin(), nums.end());
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

