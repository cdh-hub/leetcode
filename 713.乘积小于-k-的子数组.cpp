// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem713.h"

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
        int i = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i < j) i = j;
            while (i < nums.size() && mul * nums[i] < k) {
                mul *= nums[i];
                i++;
            }
            if (i > j) {
                sum += i - j;
                mul /= nums[j];
            }
        }
        return sum;
    }
};
// @lc code=end

