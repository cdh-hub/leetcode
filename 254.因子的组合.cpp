/*
 * @lc app=leetcode.cn id=254 lang=cpp
 *
 * [254] 因子的组合
 */

// @lc code=start
class Solution {
private:
    vector<int> cur;
    vector<vector<int>> res;
    void dfs(int begin, int n) {
        if (cur.size()) {
            res.push_back(cur);
            res.back().push_back(n);
        }
        for (int i = begin; i <= (int)sqrt(n); i++) {
            if (n % i == 0) {
                cur.push_back(i);
                dfs(i, n / i);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        dfs(2, n);
        return res;
    }
};
// @lc code=end

