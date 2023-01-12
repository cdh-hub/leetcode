/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mapping;
        stack<int> stk;
        for (auto num: nums2) {
            while (!stk.empty() && num > stk.top()) {
                mapping[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        vector<int> vec;
        for (auto num: nums1) {
            vec.emplace_back(mapping.count(num)?mapping[num]:-1);
        }
        return vec;
    }
};
// @lc code=end

