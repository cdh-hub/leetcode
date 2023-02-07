/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        while (m > 0 || n > 0) {
            if (m == 0) nums1[pos--] = nums2[--n];
            else if (n == 0) nums1[pos--] = nums1[--m];
            else if (nums1[m-1] > nums2[n-1]) nums1[pos--] = nums1[--m];
            else nums1[pos--] = nums2[--n];
        }
    }
};
// @lc code=end

