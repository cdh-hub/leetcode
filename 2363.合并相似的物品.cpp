/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin(), items1.end(), [](const vector<int>& x, const vector<int>& y)->bool {return x[0] < y[0];});
        sort(items2.begin(), items2.end(), [](const vector<int>& x, const vector<int>& y)->bool {return x[0] < y[0];});
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while (i < items1.size() || j < items2.size()) {
            if (j == items2.size() || i < items1.size() && items1[i][0] < items2[j][0])
                ans.emplace_back(items1[i++]);
            else if (i == items1.size() || j < items2.size() && items1[i][0] > items2[j][0])
                ans.emplace_back(items2[j++]);
            else {
                ans.emplace_back(vector<int>{items1[i][0], items1[i][1] + items2[j][1]});
                i++; j++;
            }
        }
        return ans;
    }
};
// @lc code=end

