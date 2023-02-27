/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int num: nums) {
            if (st.count(num)) return true;
            st.insert(num);
        }
        return false;
    }
};
// @lc code=end

