// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

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
        while (j < nums.size() && sum < target) {
            sum += nums[j];
            j++;
        }
        if (sum < target) return 0;
        while (sum - nums[i] >= target) {
            sum -= nums[i];
            i++;
        }
        int minLen = j - i;
        while (j < nums.size()) {
            sum += nums[j];
            while (sum - nums[i] >= target) {
                sum -= nums[i];
                i++;
            }
            j++;
            minLen = min(minLen, j-i);
        }
        return minLen;
    }
};
// @lc code=end

