/*
 * @lc app=leetcode.cn id=243 lang=cpp
 *
 * [243] 最短单词距离
 */

// @lc code=start
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> index[2];
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) index[0].push_back(i);
            else if (wordsDict[i] == word2) index[1].push_back(i);
        }
        int mindist = wordsDict.size();
        for (int i = 0; i < index[0].size(); i++) {
            for (int j = 0; j < index[1].size(); j++) {
                mindist = min(mindist, abs(index[0][i] - index[1][j]));
            }
        }
        return mindist;
    }
};
// @lc code=end

