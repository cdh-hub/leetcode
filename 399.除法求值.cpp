/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution {
private:
    unordered_map<string, pair<string, double>> disjoint_set;
    pair<string, double> find(string x) {
        if (disjoint_set[x].first == x) return disjoint_set[x];
        pair<string, double> ans = find(disjoint_set[x].first);
        return disjoint_set[x] = make_pair(ans.first, ans.second * disjoint_set[x].second);
    }
    void un(string a, string b, double value) {
        auto aRoot = find(a);
        auto bRoot = find(b);
        if (aRoot.first == bRoot.first) return;
        disjoint_set[bRoot.first] = make_pair(aRoot.first, value * aRoot.second / bRoot.second );
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = 0;
        unordered_set<string> record;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            if (!record.count(a)) {
                record.insert(a);
                disjoint_set[a] = make_pair(a, 1);
            }
            if (!record.count(b)) {
                record.insert(b);
                disjoint_set[b] = make_pair(b, 1);
            }
            un(a, b, values[i]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (record.count(queries[i][0]) && record.count(queries[i][1])) {
                auto a = find(queries[i][0]);
                auto b = find(queries[i][1]);
                if (a.first != b.first) ans.push_back(-1);
                else ans.push_back(b.second / a.second);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};
// @lc code=end

