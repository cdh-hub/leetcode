/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int, int>>> seq(1, vector<pair<int, int>>(1, make_pair(INT_MIN, 1)));
        for (int num: nums) {
            int n = seq.size();
            int left = 1, right = n-1;
            while (left <= right) {
                int mid = left+(right-left)/2;
                if (seq[mid].back().first < num) left = mid+1;
                else right = mid-1;
            }
            int m = seq[left-1].size();
            int l = 0, r = m-1;
            while (l <= r) {
                int mid = l+(r-l)/2;
                if (seq[left-1][mid].first >= num) l = mid+1;
                else r = mid-1;
            }
            if (left == n) {
                seq.push_back(vector<pair<int,int>>());
            }
            int a = seq[left-1][m-1].second;
            int b = r < 0 ? 0 : seq[left-1][r].second;
            int c = seq[left].size() > 0 ? seq[left].back().second : 0;
            seq[left].push_back(make_pair(num, a - b + c));
        }
        return seq.back().back().second;
    }
};
// @lc code=end

