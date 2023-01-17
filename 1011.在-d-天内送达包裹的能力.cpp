/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
private:
    int minDays(vector<int> & prefixSum, int w) {
        int pre = 0;
        int cnt = 1;
        for (int i = 1; i < prefixSum.size(); i++) {
            if (prefixSum[i] - prefixSum[pre] > w) {
                pre = i-1;
                cnt++;
            }
        }
        return cnt;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        vector<int> prefixSum(n + 1);
        prefixSum[0] = 0;
        int maxWeight = 0, i = 1, sum = 0;
        for (auto w: weights) {
            sum += w;
            prefixSum[i] = prefixSum[i-1] + w;
            i++;
            maxWeight = max(w, maxWeight);
        }
        int l = min(maxWeight, sum);
        int r = (n / days + 1) * maxWeight;
        while (l < r) {
            int mid = (l + r) / 2;
            if (minDays(prefixSum, mid) <= days) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

