/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 *
 * [1140] 石子游戏 II
 */

// @lc code=start
class Solution {
private:
    int** record;
    int *sum_l, *sum_r;
    int helper(vector<int>& piles, int pos, int M) {
        int ans = 0, sum = 0;
        if (record[pos][M]) return record[pos][M];
        if (piles.size() - pos <= 2*M) {
            record[pos][M] = sum_r[pos];
            return sum_r[pos];
        }
        for (int i = 0; i < 2*M; i++) {
            ans = max(ans, sum_l[pos+i+1] - sum_l[pos] + sum_r[pos+i+1] - helper(piles, pos+i+1, max(M, i+1)));
        }
        record[pos][M] = ans;
        return ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        record = new int*[n];
        for (int i = 0; i < n; i++) {
            record[i] = new int[n*2];
            for (int j = 0; j < n*2; j++) {
                record[i][j] = 0;
            }
        }
        sum_l = new int[n+1];
        sum_r = new int[n+1];
        sum_l[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum_l[i] = sum_l[i-1] + piles[i-1];
        }
        sum_r[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            sum_r[i] = sum_r[i+1] + piles[i];
        }
        return helper(piles, 0, 1);
    }
};
// @lc code=end

