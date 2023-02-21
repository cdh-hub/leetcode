/*
 * @lc app=leetcode.cn id=1326 lang=cpp
 *
 * [1326] 灌溉花园的最少水龙头数目
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // int left = 0, right = n;
        pair<int, int> a[n+1];
        for (int i = 0; i <= n; i++) {
            a[i] = make_pair(i-ranges[i], i+ranges[i]);
        }
        sort(a, a+n+1);
        int maxRight = INT_MIN;
        int left = -1;
        while (left < n && a[left+1].first <= 0) {
            maxRight = max(maxRight, a[left+1].second);
            left++;
        }
        if (left == -1) return -1;
        int cnt = 1;
        while (maxRight < n) {
            int maxLeft = maxRight;
            while (left < n && a[left+1].first <= maxLeft) {
                maxRight = max(maxRight, a[left+1].second);
                left++;
            }
            if (maxLeft == maxRight) return -1;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

