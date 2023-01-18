/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<string>> s(n+1, vector<string>(m+1, ""));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    s[i][j] = s[i-1][j-1] + str1[i-1];
                }
                else {
                    if (s[i-1][j].size() > s[i][j-1].size()) {
                        s[i][j] = s[i-1][j];
                    }
                    else {
                        s[i][j] = s[i][j-1];
                    }
                }
            }
        }
        string res = "";
        int j = 0, k = 0;
        for (int i = 0; i < s[n][m].size(); i++, j++, k++) {
            while (str1[j] != s[n][m][i]) {
                res += str1[j++];
            }
            while (str2[k] != s[n][m][i]) {
                res += str2[k++];
            }
            res += s[n][m][i];
        }
        if (j < n) res += str1.substr(j, n-j);
        if (k < m) res += str2.substr(k, m-k);
        return res;
    }
};
// @lc code=end

