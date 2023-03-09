/*
 * @lc app=leetcode.cn id=2568 lang=cpp
 *
 * [2568] 最小无法得到的或值
 */

// @lc code=start
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> st;
        for (int num: nums) st.insert(num);
        int ans = 1;
        while (st.count(ans)) ans <<= 1;
        return ans;
    }
};
// @lc code=end

