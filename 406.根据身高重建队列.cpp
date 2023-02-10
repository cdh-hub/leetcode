/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> ans(n);
        sort(people.begin(), people.end(), [](vector<int> x, vector<int> y) -> int {return x[0] == y[0] ? x[1] > y[1] : x[0] < y[0];});
        for (int i = 0; i < n; i++) {
            int m = people[i][1];
            for (int j = 0; j < n; j++) {
                if (ans[j].size() != 0) continue;
                m--;
                if (m == -1) {
                    ans[j] = people[i];
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

