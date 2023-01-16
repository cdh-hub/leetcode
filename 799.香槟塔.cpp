/*
 * @lc app=leetcode.cn id=799 lang=cpp
 *
 * [799] 香槟塔
 */

// @lc code=start

class Solution {

private:
    double** record;
    double helper(int poured, int query_row, int query_glass) {
        if (query_row == 0) return record[query_row][query_glass] = poured;
        if (record[query_row][query_glass] > -1) return record[query_row][query_glass];
        double left = 0, right = 0;
        if (query_glass > 0) left = helper(poured, query_row - 1, query_glass - 1);
        if (query_glass < query_row) right = helper(poured, query_row - 1, query_glass);
        left = left - 1 > 0 ? (left - 1) : 0;
        right = right - 1 > 0 ? (right - 1) : 0;
        return record[query_row][query_glass] = (left + right) / 2;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        record = new double*[query_row + 1];
        for (int i = 0; i <= query_row; i++) {
            record[i] = new double[i+1];
            for (int j = 0; j <= i; j++) {
                record[i][j] = -1;
            }
        }
        double res = helper(poured, query_row, query_glass);
        return res > 1 ? 1 : res;
    }
};
// @lc code=end

