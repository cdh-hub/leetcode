// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem7.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        string s = to_string(x);
        string iMin = to_string(INT_MIN);
        string iMax = to_string(INT_MAX);
        if (s[0] == '-') {
            ::reverse(s.begin()+1, s.end());
            if (s.size() >= iMin.size() && s > iMin) return 0;
            for (int i = 1; i < s.size(); i++) {
                ans = ans*10 - (s[i] - '0');
            }
        }
        else {
            ::reverse(s.begin(), s.end());
            if (s.size() >= iMax.size() && s > iMax) return 0;
            for (int i = 0; i < s.size(); i++) {
                ans = ans*10 + (s[i] - '0');
            }
        }
        return ans;
    }
};
// @lc code=end

