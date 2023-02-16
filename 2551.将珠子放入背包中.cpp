/*
 * @lc app=leetcode.cn id=2551 lang=cpp
 *
 * [2551] 将珠子放入背包中
 */

// @lc code=start
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> sum;
        for (int i = 1; i < weights.size(); i++) {
            sum.push_back((long long)weights[i-1] + (long long)weights[i]);
        }
        sort(sum.begin(), sum.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; i++) {
            ans += sum[sum.size() - i - 1] - sum[i];
        }
        return ans;
    }
};
// @lc code=end

