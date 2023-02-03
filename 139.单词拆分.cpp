/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for (auto word: wordDict) {
            set.insert(word);
        }
        vector<int> index(1, -1);
        for (int i = 0; i < s.size(); i++) {
            for (auto ind: index) {
                if (set.count(s.substr(ind+1, i-ind))) {
                    index.push_back(i);
                    break;
                }
            }
        }
        return index.back() == s.size()-1;
    }
};
// @lc code=end

