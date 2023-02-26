/*
 * @lc app=leetcode.cn id=1255 lang=cpp
 *
 * [1255] 得分最高的单词集合
 */

// @lc code=start
class Solution {
private:
    int curScore, maxScore;
    void dfs(vector<string>& words, int pos, int mp[], vector<int>& score) {
        if (pos == words.size()) {
            maxScore = max(maxScore, curScore);
            return;
        }
        dfs(words, pos+1, mp, score);
        int i = 0, tmp = curScore;
        for (i = 0; i < words[pos].size(); i++) {
            if (mp[words[pos][i]-'a']) {
                mp[words[pos][i]-'a']--;
                curScore += score[words[pos][i]-'a'];
            }
            else break;
        }
        if (i == words[pos].size()) dfs(words, pos+1, mp, score);
        curScore = tmp;
        while (i--) {
            mp[words[pos][i]-'a']++;
        }
    }
public:
    Solution() : curScore(0), maxScore(0) {}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int mp[26] = {0};
        for (char ch: letters) mp[ch-'a']++;
        dfs(words, 0, mp, score);
        return maxScore;
    }
};
// @lc code=end

