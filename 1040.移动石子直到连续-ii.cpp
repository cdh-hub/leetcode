/*
 * @lc app=leetcode.cn id=1040 lang=cpp
 *
 * [1040] 移动石子直到连续 II
 */

// @lc code=start
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int maximum_moves = max(stones[n-1] - stones[1] - n + 2, stones[n-2] - stones[0] - n + 2);
        int minimum_moves = INT_MAX;
        int window_l = stones[0], window_r = stones[0] + n - 1;
        int i = 0, j = 0, cnt = 0;
        while (j < n && stones[j] <= window_r) cnt++, j++;
        if (n - cnt == 1 && stones[j-1] == window_r - 1) minimum_moves = 2;
        else minimum_moves = min(n - cnt, minimum_moves);
        while (j < n) {
            i++;
            window_l = stones[i];
            cnt--;
            window_r = window_l + n -1;
            while (j < n && stones[j] <= window_r) cnt++, j++;
            if (n - cnt == 1 && stones[j-1] == window_r - 1) minimum_moves = 2;
            else minimum_moves = min(n - cnt, minimum_moves);
        }
        return {minimum_moves, maximum_moves};
    }
};
// @lc code=end

