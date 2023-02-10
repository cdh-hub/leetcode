/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int partation(vector<pair<int, int>>& vec, int l, int r) {
        auto x = vec[l];
        while (l < r) {
            while (l < r && vec[r].second < x.second) r--;
            vec[l] = vec[r];
            while (l < r && vec[l].second >= x.second) l++;
            vec[r] = vec[l];
        }
        vec[l] = x;
        return l;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) map[num]++;
        vector<pair<int, int>> vec;
        for (auto [k, v]: map) {
            vec.push_back(make_pair(k, v));
        }
        srand(time(nullptr));
        int l = 0, r = vec.size()-1;
        do {
            int random = l + rand() % (r-l+1);
            swap(vec[l], vec[random]);
            int pos = partation(vec, l, r);
            if (pos == k) break;
            if (pos < k) l = pos + 1;
            else r = pos - 1;
        } while(l < r);
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};
// @lc code=end

