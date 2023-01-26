/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        for (auto kv: map) {
            int k2 = target - kv.first;
            if (k2 == kv.first && kv.second.size() > 1) {
                return {kv.second[0], kv.second[1]};
            }
            else if (k2 != kv.first && map.count(k2)) {
                return {kv.second[0], map[k2][0]};
            }
        }
        return {};
    }
};
// @lc code=end

