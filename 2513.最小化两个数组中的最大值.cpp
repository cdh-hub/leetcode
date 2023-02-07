/*
 * @lc app=leetcode.cn id=2513 lang=cpp
 *
 * [2513] 最小化两个数组中的最大值
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool check(int d1, int d2, int c1, int c2, int maxValue) {
        int cnt = maxValue;
        int not1 = maxValue / d1;
        int not2 = maxValue / d2;
        int both_not = (int) (maxValue / ((long long)d1 / __gcd(d1, d2) * d2));
        cnt = cnt - not1 - not2 + both_not;
        c1 = max(0, c1 - not2 + both_not);
        c2 = max(0, c2 - not1 + both_not);
        return cnt >= c1 + c2;
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l = 2, r = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

