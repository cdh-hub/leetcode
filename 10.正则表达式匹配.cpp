/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
private:
    bool record[25][35];
    bool hasCheck[25][35] = {false};
public:
    bool isMatch(string s, string p) {
        if (hasCheck[s.size()][p.size()]) return record[s.size()][p.size()];
        int i = 0, j = 0;
        while (j < p.size()) {
            if (p[j] == '.') {
                if (j + 1 == p.size() || p[j+1] != '*') {
                    if (i < s.size()) {
                        i++;
                        j++;
                    }
                    else {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = false;
                        return false;
                    }
                }
                else {
                    while (i <= s.size() && !isMatch(s.substr(i, s.size()-i), p.substr(j+2, p.size()-j-2))) {
                        i++;
                    }
                    if (i > s.size()) {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = false;
                        return false;
                    }
                    else {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = true;
                        return true;
                    }
                }
            }
            else {
                if (j + 1 == p.size() || p[j+1] != '*') {
                    if (i < s.size() && s[i] == p[j]) {
                        i++;
                        j++;
                    }
                    else {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = false;
                        return false;
                    }
                }
                else {
                    int tmp = i;
                    while (i <= s.size() && (i == tmp || s[i-1] == p[j]) && !isMatch(s.substr(i, s.size()-i), p.substr(j+2, p.size()-j-2))) {
                        i++;
                    }
                    if (i > s.size() || i != tmp && s[i-1] != p[j]) {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = false;
                        return false;
                    }
                    else {
                        hasCheck[s.size()][p.size()] = true;
                        record[s.size()][p.size()] = true;
                        return true;
                    }
                }
            }
        }
        record[s.size()][p.size()] = (j == p.size() && i == s.size());
        return record[s.size()][p.size()];
    }
};
// @lc code=end

