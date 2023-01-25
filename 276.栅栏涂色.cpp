/*
 * @lc app=leetcode.cn id=276 lang=cpp
 *
 * [276] 栅栏涂色
 */

// @lc code=start
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k*k;
        int a[3] = {1, k, k*k-1};
        for (int i = 3; i < n; i++) {
            int tmp = a[2] * k - a[0] * (k-1);
            a[0] = a[1];
            a[1] = a[2];
            a[2] = tmp;    
        }
        return k * a[2];
    }
};
// @lc code=end

