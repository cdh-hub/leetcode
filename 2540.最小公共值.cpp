/*
 * @lc app=leetcode.cn id=2540 lang=cpp
 *
 * [2540] 最小公共值
 */

// @lc code=start
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while (i < n && j < m && nums1[i] != nums2[j]) {
            if (nums1[i] > nums2[j]) j++;
            else i++;
        }
        if (i == n || j == m) return -1;
        else return nums1[i];
    }
};
// @lc code=end

