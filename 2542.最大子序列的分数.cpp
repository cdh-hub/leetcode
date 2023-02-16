/*
 * @lc app=leetcode.cn id=2542 lang=cpp
 *
 * [2542] 最大子序列的分数
 */

// @lc code=start
typedef long long ll;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a > b;
}
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int> > nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = make_pair(nums2[i], nums1[i]);
        }
        sort(nums.begin(), nums.end(), cmp);
        ll sum = 0, minNum = INT_MAX;
        priority_queue<int, vector<int>, greater<int> > q;
        for (int i = 0; i < k; i++) {
            sum += nums[i].second;
            minNum = min<ll>(minNum, nums[i].first);
            q.push(nums[i].second);
        }
        ll maxScore = sum * minNum;
        for (int i = k; i < n; i++) {
            sum -= q.top();
            q.pop();
            sum += nums[i].second;
            q.push(nums[i].second);
            minNum = nums[i].first;
            maxScore = max(maxScore, sum * minNum);
        }
        return maxScore;
    }
};
// @lc code=end

