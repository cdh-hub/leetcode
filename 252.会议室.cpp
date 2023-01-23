/*
 * @lc app=leetcode.cn id=252 lang=cpp
 *
 * [252] 会议室
 */

// @lc code=start
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    else return a[0] < b[0];
    
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) return false;
        }
        return true;
    }
};
// @lc code=end

