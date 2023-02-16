/*
 * @lc app=leetcode.cn id=2541 lang=cpp
 *
 * [2541] 使数组中所有元素相等的最小操作数 II
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] > nums2[i]) {
                int diff = nums1[i] - nums2[i];
                if (!k || diff % k) return -1;
                sum1 += diff;
            }
            if (nums1[i] < nums2[i]) {
                int diff = nums2[i] - nums1[i];
                if (!k || diff % k) return -1;
                sum2 += diff;
            }
        }
        if (sum1 != sum2 || k == 0 && sum1 != 0) return -1;
        else if (k == 0 && sum1 == 0) return 0;
        else return sum1 / k;
    }
};
// @lc code=end

