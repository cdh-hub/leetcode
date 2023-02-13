/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 1, j = numbers.size();
        while (i < j) {
            if (numbers[i-1] + numbers[j-1] == target) {
                return {i, j};
            }
            else if (numbers[i-1] + numbers[j-1] < target) {
                i++;
            }
            else {
                j--;
            }
        }
        return {};
    }
};
// @lc code=end

