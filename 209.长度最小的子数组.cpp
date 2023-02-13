// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int i = 0, j = 0;
        int ans = nums.size() + 1;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }
        return ans > nums.size() ? 0 : ans;
    }
};
// @lc code=end

