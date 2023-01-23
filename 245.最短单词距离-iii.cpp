/*
 * @lc app=leetcode.cn id=245 lang=cpp
 *
 * [245] 最短单词距离 III
 */

// @lc code=start
class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int last1 = -1, last2 = -1, minDist = wordsDict.size();
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                if (last2 != -1) minDist = min(minDist, i - last2);
                last1 = i;
            }
            if (wordsDict[i] == word2) {
                if (last1 != -1) minDist = (i == last1 ? minDist : min(minDist, i - last1));
                last2 = i;
            }
        }
        return minDist;
    }
};
// @lc code=end

