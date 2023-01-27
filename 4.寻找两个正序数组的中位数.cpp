/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0, k = (m + n + 1) / 2 - 1;
        while (index1 + index2 < k) {
            if (index1 == m) {
                index2 = k - m;
                break;
            }
            if (index2 == n) {
                index1 = k - n;
                break;
            }
            int left = k - index1 - index2;
            if (left == 1) {
                if(nums1[index1] < nums2[index2]) index1++;
                else index2++;
                break;
            }
            int i = min(m - 1, index1 + left / 2 - 1), j = min(n - 1, index2 + left / 2 - 1);
            if (nums1[i] < nums2[j]) {
                index1 = i + 1;
            }
            else {
                index2 = j + 1;
            }
        }
        if ((m + n) % 2 == 1) {
            if (index1 < m && index2 < n) return min(nums1[index1], nums2[index2]);
            if (index1 < m) return nums1[index1];
            return nums2[index2];
        }
        else {
            double a, b;
            if (index1 < m && index2 < n) {
                if (nums1[index1] < nums2[index2]) a = nums1[index1++];
                else a = nums2[index2++];
                if (index1 < m && index2 < n) b = min(nums1[index1], nums2[index2]);
                else if (index1 < m) b = nums1[index1];
                else b = nums2[index2];
            }
            else if (index1 < m) {
                a = nums1[index1];
                b = nums1[index1+1];
            }
            else {
                a = nums2[index2];
                b = nums2[index2+1];
            }
            return (a + b) / 2;
        }
    }
};
// @lc code=end

