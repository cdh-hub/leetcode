/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
private:
    vector<vector<bool>> record;
    bool backtrack(vector<vector<char>>& board, string& word, int index1, int index2) {
        if (index2 == word.size()) return true;
        int m = board.size(), n = board[0].size();
        int x = index1 / n, y = index1 % n;
        if (board[x][y] != word[index2]) return false;
        if (index2 == word.size() - 1) return true;
        record[x][y] = true;
        if (x > 0 && !record[x-1][y] && backtrack(board, word, (x-1)*n+y, index2+1)) return true;
        if (y > 0 && !record[x][y-1] && backtrack(board, word, x*n+y-1, index2+1)) return true;
        if (x < m - 1 && !record[x+1][y] && backtrack(board, word, (x+1)*n+y, index2+1)) return true;
        if (y < n - 1 && !record[x][y+1] && backtrack(board, word, x*n+y+1, index2+1)) return true;
        record[x][y] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        record.resize(board.size());
        for (int i = 0; i < board.size(); i++) {
            record[i].resize(board[0].size());
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (backtrack(board, word, i*board[i].size()+j, 0)) return true;
            }
        }
        return false;
    }
};
// @lc code=end

