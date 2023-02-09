/*
 * @lc app=leetcode.cn id=2521 lang=cpp
 *
 * [2521] 数组乘积中的不同质因数数目
 */

// @lc code=start
class Solution {
private:
    unordered_set<int> set;
    bool isPrime(int x) {
        if (set.count(x)) return true;
        for (auto s: set) {
            if (x % s == 0) return false;
        }
        set.insert(x);
        return true;
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        for (int i = 2; i < 1000; i++) isPrime(i);
        int count = 0;
        for (auto k: set) {
            for (auto num: nums) {
                if (num % k == 0) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
// @lc code=end

