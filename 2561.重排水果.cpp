/*
 * @lc app=leetcode.cn id=2561 lang=cpp
 *
 * [2561] 重排水果
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int mn = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));
        map<int, int> map1, map2;
        for (auto a: basket1) {
            map1[a]++;
        }
        int count = basket1.size();
        for (auto a: basket2) {
            if (map1.count(a)) {
                count--;
                map1[a]--;
                if (map1[a] == 0) map1.erase(a);
            }
            else map2[a]++;
        }
        for (auto [k, v]: map1) {
            if (v % 2 != 0) return -1;
        }
        for (auto [k, v]: map2) {
            if (v % 2 != 0) return -1;
        }
        long long cost = 0;
        auto it1 = map1.begin(), it2 = map2.begin(); 
        for (int i = 0; i < count / 2; i++) {
            if ((*it1).first < (*it2).first) {
                cost += min(2 * mn, (*it1).first);
                (*it1).second -= 2;
                if ((*it1).second == 0) it1++;
            }
            else {
                cost += min(2 * mn, (*it2).first);
                (*it2).second -= 2;
                if ((*it2).second == 0) it2++;
            }        
        }
        return cost;
    }
};
// @lc code=end