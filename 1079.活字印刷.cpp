/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] 活字印刷
 */

// @lc code=start
class Solution {
private:
    int dfs(string& tiles, vector<bool>& record) {
        int res = 0;
        int n = tiles.size();
        for (int i = 0; i < n; i++) {
            if (!record[i] && (i == 0 || tiles[i] != tiles[i-1] || record[i-1])) {
                record[i] = true;
                res += dfs(tiles, record) + 1;
                record[i] = false;
            }
        }
        return res;
    } 
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> record(tiles.size(), false);
        return dfs(tiles, record);
    }
};
// @lc code=end

