/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix[nums.size()+1];
        prefix[0] = 0;
        int i = 0;
        for (int num: nums) {
            prefix[i+1] = prefix[i] + num;
            i++;
        }
        unordered_map<int, int> mp;
        int ans = 0;
        for (int pre: prefix) {
            if(mp.count(pre-k)) ans += mp[pre-k];
            mp[pre]++;
        }
        return ans;
    }
};
// @lc code=end

