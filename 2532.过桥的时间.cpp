/*
 * @lc app=leetcode.cn id=2532 lang=cpp
 *
 * [2532] 过桥的时间
 */

// @lc code=start
class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        stable_sort(time.begin(), time.end(), [](const vector<int>& a, const vector<int>& b)->bool {
            return (a[0]+a[2]) < (b[0]+b[2]);
        });
        int cur = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work_l, work_r;
        priority_queue<int> wait_l, wait_r;
        for (int i = 0; i < time.size(); i++) {
            wait_l.push(i);
        }
        int bridge_time = 0;
        while (n) {
            while (!work_l.empty() && work_l.top().first <= cur) {
                wait_l.push(work_l.top().second);
                work_l.pop();
            }
            while (!work_r.empty() && work_r.top().first <= cur) {
                wait_r.push(work_r.top().second);
                work_r.pop();
            }
            if (bridge_time <= cur) {
                if (!wait_r.empty()) {
                    bridge_time = cur + time[wait_r.top()][2];
                    work_l.push(make_pair(bridge_time+time[wait_r.top()][3], wait_r.top()));
                    wait_r.pop();
                }
                else if (!wait_l.empty()) {
                    bridge_time = cur + time[wait_l.top()][0];
                    work_r.push(make_pair(bridge_time+time[wait_l.top()][1], wait_l.top()));
                    wait_l.pop();
                    --n;
                }
                else {
                    if (work_l.empty()) cur = work_r.top().first;
                    else if (work_r.empty()) cur = work_l.top().first;
                    else cur = min(work_r.top().first, work_l.top().first);
                }
            }
            else cur = bridge_time;
        }
        while (!work_r.empty() || !wait_r.empty() || bridge_time > cur) {
            while (!work_r.empty() && work_r.top().first <= cur) {
                wait_r.push(work_r.top().second);
                work_r.pop();
            }
            if (bridge_time <= cur) {
                if (!wait_r.empty()) {
                    bridge_time = cur + time[wait_r.top()][2];
                    wait_r.pop();
                }
                else {
                    cur = work_r.top().first;
                }
            }
            else cur = bridge_time;
        }
        return cur;
    }
};
// @lc code=end

