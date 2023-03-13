/*
 * @lc app=leetcode.cn id=2572 lang=cpp
 *
 * [2572] 无平方子集计数
 */

// @lc code=start
class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int sf_to_mask[31] = {0};
        for (int i = 1; i <= 30; i++) {
            int j = 0;
            for (int p: primes) {
                if (i % (p*p) == 0) {
                    sf_to_mask[i] = -1;
                    break;
                }
                else if (i % p == 0) sf_to_mask[i] |= 1 << j;
                j++;
            }
        }
        int MOD = 1000000007;
        int n = nums.size();
        int dp[1<<10];
        for (int j = 0; j < (1<<10); j++) {
            dp[j] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (sf_to_mask[nums[i-1]] >= 0) for (int j = (1<<10)-1; j >= sf_to_mask[nums[i-1]]; j--) {
                if ((j | sf_to_mask[nums[i-1]]) == j) {
                    dp[j] = (dp[j] + dp[j^sf_to_mask[nums[i-1]]]) % MOD;
                }
            }
        }
        // function<int(int,int)> dfs = [&](int i, int c) -> int {
        //     if (i < 0) {
        //         return 1;
        //     }
        //     if (cache[i][c] == -1) {
        //         if ((c | sf_to_mask[nums[i]]) != c) cache[i][c] = dfs(i-1, c);
        //         else cache[i][c] = (dfs(i-1, c) + dfs(i-1, c ^ sf_to_mask[nums[i]])) % MOD;
        //     }
        //     return cache[i][c];
        // };
        return (dp[(1<<10)-1]+MOD-1)%MOD;
    }
};
// @lc code=end

