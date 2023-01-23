/*
 * @lc app=leetcode.cn id=253 lang=cpp
 *
 * [253] 会议室 II
 */

// @lc code=start
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> times;
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i++) {
            int tag = false;
            for (int& t: times) {
                if (intervals[i][0] >= t) {
                    t = intervals[i][1];
                    tag = true;
                    break;
                }
            }
            if (!tag) {
                times.push_back(intervals[i][1]);
            }
        }
        return times.size();
    }
};
// @lc code=end

