/*
 * @lc app=leetcode.cn id=2523 lang=cpp
 *
 * [2523] 范围内最接近的两个质数
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
vector<bool> isPrime(1000001, true);
class Solution {
private:
    set<int> set;
public:
    vector<int> closestPrimes(int left, int right) {
        if (right <= 2) return {-1, -1};
        isPrime[0] = false;
        isPrime[1] = false;
        vector<int> prime;
        for (int i = 2; i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i*2; j <= right; j+=i) isPrime[j] = false;
                prime.push_back(i);
            }
        }
        int minValue = INT_MAX;
        int l = 0;
        while (l < prime.size() && prime[l] < left) l++;
        if (l >= prime.size() - 1) return {-1, -1};
        int minl = l;
        while (l < prime.size()-1 && prime[l+1] <= right) {
            if (prime[l+1] - prime[l] < minValue) {
                minValue = prime[l+1] - prime[l];
                minl = l;
            }
            if (minValue == 1) return {prime[minl], prime[minl+1]};
            if (minValue == 2) return {prime[minl], prime[minl+1]};
            l++;
        }
        if (minValue == INT_MAX) return {-1, -1};
        else return {prime[minl], prime[minl+1]};
    }
};
// @lc code=end
int main()
{
    Solution s;
    s.closestPrimes(1, 1000000);
    return 0;
}
