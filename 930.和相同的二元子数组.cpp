/*
 * @lc app=leetcode.cn id=930 lang=cpp
 *
 * [930] 和相同的二元子数组
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mapping;
        int prefix = 0;
        mapping[0]++;
        int cnt = 0;
        for (int i = 1; i <= nums.size(); i++) {
            prefix += nums[i-1];
            if (mapping.count(prefix - goal)) {
                cnt += mapping[prefix - goal];
            }
            mapping[prefix]++;
        }
        return cnt;
    }
};
// @lc code=end

