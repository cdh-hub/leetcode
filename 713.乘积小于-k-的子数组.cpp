// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int mul = 1;
        int i = 0, ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            mul *= nums[j];
            while (i <= j && mul >= k) {
                mul /= nums[i++];
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
// @lc code=end

