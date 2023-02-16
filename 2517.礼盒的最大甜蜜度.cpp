/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
class Solution {
private:
    bool check(vector<int>& price, int sweet, int k) {
        int count = 1, pre = 0, cur = 0;
        while (count < k && cur < price.size()) {
            while (cur < price.size() && price[cur] - price[pre] < sweet) cur++;
            if (cur < price.size()) {
                pre = cur;
                count++;
            }
        }
        return count == k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int l = 0, r = price[price.size()-1] - price[0];
        while (l <= r) {
            int mid = l+(r-l)/2;
            if (check(price, mid, k)) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return r;
    }
};
// @lc code=end

