/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
private:
    string getInstruction(int& pos, char ch) {
        int x1 = pos / 5, y1 = pos % 5;
        int x2 = (ch - 'a') / 5, y2 = (ch -'a') % 5;
        pos = x2 * 5 + y2;
        string ans;
        if (x1 != 5 || y1 != 0) {
            if (y2 > y1) for (int i = 0; i < y2-y1; i++) ans.push_back('R');
            else for (int i = 0; i < y1-y2; i++) ans.push_back('L');
            if (x2 > x1) for (int i = 0; i < x2-x1; i++) ans.push_back('D');
            else for (int i = 0; i < x1-x2; i++) ans.push_back('U');
        }
        else {
            for (int i = 0; i < x1-x2; i++) ans.push_back('U');
            for (int i = 0; i < y2-y1; i++) ans.push_back('R');
        }
        ans.push_back('!');
        return ans;
    }
public:
    string alphabetBoardPath(string target) {
        int pos = 0;
        string ans;
        for (char ch: target) {
            ans += getInstruction(pos, ch);
        }
        return ans;
    }
};
// @lc code=end

