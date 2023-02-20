/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int i = 1;
        for (; i < 5; i++) {
            if (suits[i] != suits[0]) break;
        }
        if (i == 5) return "Flush";
        sort(ranks.begin(), ranks.end());
        int count = 1, maxCount = 1;
        for (i = 1; i < 5; i++) {
            if (ranks[i] == ranks[i-1]) {
                count++;
                maxCount = max(maxCount, count);
            }
            else {
                count = 1;
            }
        }
        if (maxCount >= 3) return "Three of a Kind";
        if (maxCount == 2) return "Pair";
        return "High Card";
    }
};
// @lc code=end

