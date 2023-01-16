/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool is_jewel[52] = {false};
        for (auto j : jewels) {
            if (j >= 'a' && j <= 'z') {
                is_jewel[j-'a'] = true;
            }
            else {
                is_jewel[j-'A'+26] = true;
            }
        }
        int count = 0;
        for (auto s: stones) {
            if (s >= 'a' && s <= 'z' && is_jewel[s-'a'] || s >= 'A' && s <= 'Z' && is_jewel[s-'A'+26]) {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end

