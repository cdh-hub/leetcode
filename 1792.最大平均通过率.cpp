/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 */

// @lc code=start
class Cmp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (double)(a.first+1) / (a.second+1) - (double)a.first / a.second < (double)(b.first+1) / (b.second+1) - (double)b.first / b.second;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> heap;
        for (auto c: classes) {
            heap.push(make_pair(c[0], c[1]));
        }
        while (extraStudents--) {
            auto t = heap.top();
            heap.pop();
            heap.push(make_pair(t.first+1, t.second+1));
        }
        double ans = 0;
        while (!heap.empty()) {
            ans += (double)heap.top().first / heap.top().second;
            heap.pop();
        }
        return ans / classes.size();
    }
};
// @lc code=end

