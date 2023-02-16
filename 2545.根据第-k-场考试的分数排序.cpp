/*
 * @lc app=leetcode.cn id=2545 lang=cpp
 *
 * [2545] 根据第 K 场考试的分数排序
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size();
        int m = score[0].size();
        vector<vector<int>> newscore(n);
        vector<pair<int, int>> helper(n);
        for (int i = 0; i < n; i++) {
            helper[i] = make_pair(score[i][k], i);
        }
        sort(helper.begin(), helper.end());
        for (int i = 0; i < n; i++) {
            newscore[i] = score[helper[n-i-1].second];
        }
        return newscore;
    }
};
// @lc code=end

