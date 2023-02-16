/*
 * @lc app=leetcode.cn id=2550 lang=cpp
 *
 * [2550] 猴子碰撞的方法数
 */

// @lc code=start
const int MOD = 1e9 + 7;
typedef long long ll;
class Solution {
private:
    ll ksm(ll a, int n) {
        ll ans = 1;
        while (n) {
            if (n & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            n /= 2;
        }
        return ans;
    }
public:
    int monkeyMove(int n) {
        return (int) ((ksm(2, n) + MOD - 2) % MOD);
    }
};
// @lc code=end

