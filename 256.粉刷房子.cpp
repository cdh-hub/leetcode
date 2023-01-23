/*
 * @lc app=leetcode.cn id=256 lang=cpp
 *
 * [256] 粉刷房子
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int mCost[2][3] = {{0, 0, 0}, {0, 0, 0}};
        int tag = 0;
        for (int i = 0; i < costs.size(); i++) {
            mCost[1-tag][0] = costs[i][0] + min(mCost[tag][1], mCost[tag][2]);
            mCost[1-tag][1] = costs[i][1] + min(mCost[tag][2], mCost[tag][0]);
            mCost[1-tag][2] = costs[i][2] + min(mCost[tag][0], mCost[tag][1]);
            tag = 1 - tag;
        }
        return min(min(mCost[tag][0], mCost[tag][1]), mCost[tag][2]);
    }
};
// @lc code=end

