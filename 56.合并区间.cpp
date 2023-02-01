/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans[ans.size()-1][1]) {
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

