/*
 * @lc app=leetcode.cn id=2555 lang=cpp
 *
 * [2555] 两个线段获得的最多奖品
 */

// @lc code=start
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        int pre[n + 1];
        pre[0] = 0;
        int right = 0, left = 0, ans = 0;
        for (right = 0; right < n; right++) {
            while (prizePositions[right] - prizePositions[left] > k) left++;
            ans = max(ans, right - left + 1 + pre[left]);
            pre[right+1] = max(pre[right], right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

