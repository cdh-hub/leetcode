/*
 * @lc app=leetcode.cn id=4 lang=java
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            int[] tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        int m = nums1.length, n = nums2.length;
        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r) / 2;
            int mid2 = (m + n) / 2 - mid;
            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
            int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;
            if (mid > 0) l1 = nums1[mid-1];
            if (mid < m) r1 = nums1[mid];
            if (mid2 > 0) l2 = nums2[mid2-1];
            if (mid2 < n) r2 = nums2[mid2];
            if (l1 > r2) {
                r = mid - 1;
            }
            else if (l2 > r1) {
                l = mid + 1;
            }
            else break;
        }
        int mid = (l + r) / 2, mid2 = (m + n) / 2 - mid;
        int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE;
        int r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;
        if (mid > 0) l1 = nums1[mid-1];
        if (mid < m) r1 = nums1[mid];
        if (mid2 > 0) l2 = nums2[mid2-1];
        if (mid2 < n) r2 = nums2[mid2];
        if ((m + n) % 2 == 1) return Math.min(r1, r2);
        else return (Math.max(l1, l2) + Math.min(r1, r2)) / 2.0;
    }
}
// @lc code=end

