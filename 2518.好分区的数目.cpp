/*
 * @lc app=leetcode.cn id=2518 lang=cpp
 *
 * [2518] 好分区的数目
 */

// @lc code=start
typedef long long ll;
class Solution {
private:
    const int MOD = 1000000007;
    int ksm(ll a, int n) {
        ll ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            n /= 2;
        }
        return (int)ans;
    }
public:
    int countPartitions(vector<int>& nums, int k) {
        ll sum = 0;
        for (int num: nums) sum += num;
        if (sum < k*2) return 0;
        int dp[k];
        for (int i = 0; i < k; i++) dp[i] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = k-1; j >= 0; j--) {
                dp[j] = (dp[j] + (nums[i] <= j ? dp[j-nums[i]] : 0)) % MOD;
            }
        }
        return (ksm(2, nums.size()) - ((2*dp[k-1])%MOD) + MOD) % MOD;
    }
};
// @lc code=end

