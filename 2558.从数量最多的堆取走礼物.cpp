/*
 * @lc app=leetcode.cn id=2558 lang=cpp
 *
 * [2558] 从数量最多的堆取走礼物
 */

// @lc code=start
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (auto g: gifts) {
            q.push(g);
        }
        while(k--) {
            int a = (int) sqrt(q.top());
            q.pop();
            q.push(a);
        }
        long long s=0;
        while(!q.empty()) {
            s+=q.top();
            q.pop();
        }
        return s;
    }
};
// @lc code=end

