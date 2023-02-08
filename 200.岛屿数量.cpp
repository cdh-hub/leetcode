// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem200.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<pair<int, int>>> disjoint_set;
    void initialize(int m, int n) {
        disjoint_set.resize(m, vector<pair<int, int>>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                disjoint_set[i][j] = make_pair(i,j);
            }
        }
    }
    pair<int, int> find(int x, int y) {
        if (disjoint_set[x][y].first != x || disjoint_set[x][y].second != y) {
            disjoint_set[x][y] = find(disjoint_set[x][y].first, disjoint_set[x][y].second);
        }
        return disjoint_set[x][y];
    }
    void un(int x1, int y1, int x2, int y2) {
        auto r1 = find(x1, y1), r2 = find(x2, y2);
        disjoint_set[r1.first][r1.second] = disjoint_set[r2.first][r2.second];
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        initialize(grid.size(), grid[0].size());
        int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    for (int k = 0; k < 4; k++) {
                        if (i + dir[k][0] < m && i + dir[k][0] >= 0 
                            && j + dir[k][1] < n && j + dir[k][1] >= 0
                            && grid[i + dir[k][0]][j + dir[k][1]] == '1') {
                                un(i, j, i + dir[k][0], j + dir[k][1]);
                            }
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && disjoint_set[i][j].first == i && disjoint_set[i][j].second == j) {
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

