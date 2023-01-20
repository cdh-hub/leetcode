/*
 * @lc app=leetcode.cn id=758 lang=cpp
 *
 * [758] 字符串中的加粗单词
 */

// @lc code=start
class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        vector<bool> vec(s.size(), false);
        for (auto word: words) {
            for (int i = 0; i <= s.size() - word.size() ; i++) {
                if (!s.compare(i, word.size(), word)) {
                    for (int j = i; j < i+word.size(); j++) {
                        vec[j] = true;
                    }
                }
            }
        }
        string newstr = "";
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] && (i == 0 || !vec[i-1])) {
                newstr += "<b>";
            }
            newstr += s[i];
            if (vec[i] && (i == vec.size() - 1 || !vec[i+1])) {
                newstr += "</b>";
            }
        }
        return newstr;
    }
};
// @lc code=end

