/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Less {
public:
    bool operator()(const vector<int> a, const vector<int> b) const {
        return a[1] - a[0] > b[1] - b[0];
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<vector<int>, vector<vector<int>>, Less> qa;
        int res = 0, n = costs.size();
        for (auto cost: costs) {
            qa.push(cost);
            res += cost[0];
        }
        for (int i = 0; i < n/2; i++) {
            res += qa.top()[1] - qa.top()[0];
            qa.pop();
        }
        return res;
    }
};
// @lc code=end

