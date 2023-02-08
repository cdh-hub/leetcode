/*
 * @lc app=leetcode.cn id=2528 lang=cpp
 *
 * [2528] 最大化城市的最小供电站数目
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    bool check(vector<int>& stations, int r, int k, long long power) {
        int n = stations.size();
        vector<long long> sta2(n);
        long long cur = 0;
        for (int i = 0; i <= r; i++) {
            cur += stations[i];
        }
        for (int i = 0; i < n; i++) {
            sta2[i] = (cur > power ? 0 : (power - cur));
            if (i + r + 1 < n) cur += stations[i+r+1];
            if (i - r >= 0) cur -= stations[i-r];
        }
        vector<long long> help(n, 0);
        cur = 0;
        for (int i = 0; i < n; i++) {
            if (sta2[i] > 0) {
                if (sta2[i] > cur) {
                    k -= sta2[i] - cur;
                    if (i+2*r < n) help[i+2*r] += sta2[i] - cur;
                    cur = sta2[i];
                }
                if (k < 0) return false;
            }
            cur -= help[i];
        }
        return k >= 0;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long sum = k;
        for (auto s: stations) sum += s;
        long long left = 0, right = sum;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (check(stations, r, k, mid)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> a({1,2,4,5,0});
    s.maxPower(a, 1, 2);
}