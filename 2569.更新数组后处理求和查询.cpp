/*
 * @lc app=leetcode.cn id=2569 lang=cpp
 *
 * [2569] 更新数组后处理求和查询
 */

// @lc code=start
class Solution {
private:
    long long* v;
    bool* lazy;
    void build(int o, int l, int r, vector<int>& nums1) {
        if (l == r) {
            v[o] = nums1[l-1];
            return;
        }
        int mid = l + (r-l)/2;
        build(o*2, l, mid, nums1);
        build(o*2+1, mid+1, r, nums1);
        v[o] = v[o*2] + v[o*2+1];
    }
    void update(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            v[o] = r-l+1-v[o];
            lazy[o] = !lazy[o];
            return;
        }
        int mid = l + (r - l) / 2;
        if (lazy[o]) {
            v[o*2] = mid - l + 1 - v[o*2];
            v[o*2+1] = r - mid - v[o*2+1];
            lazy[o*2] = !lazy[o*2];
            lazy[o*2+1] = !lazy[o*2+1];
            lazy[o] = false;
        }
        if (mid >= L) update(o*2, l, mid, L, R);
        if (mid < R) update(o*2+1, mid+1, r, L, R);
        v[o] = v[o*2] + v[o*2+1];
    }
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        v = new long long[4*n+10];
        lazy = new bool[4*n+10];
        fill(lazy, lazy+4*n+10, false);
        build(1, 1, n, nums1);
        vector<long long> ans;
        long long sum = 0;
        for (int num: nums2) sum += num;
        for (auto& q: queries) {
            if (q[0] == 1) {
                update(1, 1, n, q[1]+1, q[2]+1);
            }
            else if (q[0] == 2) {
                sum += (long long) q[1] * v[1];
            }
            else {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
// @lc code=end

