/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxcnt = 1, cnt = 1, p = 1, q = 0;
        int type1 = fruits[0], type2 = -1;
        while (p < fruits.size()) {
            if (fruits[p] == type1 || fruits[p] == type2) cnt++;
            else if (type2 == -1) {
                type2 = fruits[p];
                cnt++;
            }
            else {
                type1 = fruits[q];
                type2 = fruits[p];
                maxcnt = max(maxcnt, cnt);
                cnt = p - q + 1;
            }
            if (fruits[p] != fruits[p-1]) q = p;
            p++;
        }
        maxcnt = max(maxcnt, cnt);
        return maxcnt;
    }
};
// @lc code=end

