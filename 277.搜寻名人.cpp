/*
 * @lc app=leetcode.cn id=277 lang=cpp
 *
 * [277] 搜寻名人
 */

// @lc code=start
/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (!knows(i, cur)) cur = i;
        }
        for (int i = 0; i < n; i++) {
            if (i != cur && (!knows(i, cur) || knows(cur, i))) return -1;
        }
        return cur;
    }
};
// @lc code=end

