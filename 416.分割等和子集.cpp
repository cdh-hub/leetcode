/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums) {
            sum += n;
        }
        if (sum & 1) return false;
        int mid = sum >> 1;
        unordered_set<int> set;
        set.insert(0);
        for (auto n: nums) {
            vector<int> tmp;
            for (auto s: set) {
                if (s+n==mid) return true;
                tmp.push_back(s+n);
            }
            for (auto s: tmp) set.insert(s);
        }
        return false;
    }
};
// @lc code=end

