/*
 * @lc app=leetcode.cn id=244 lang=cpp
 *
 * [244] 最短单词距离 II
 */

// @lc code=start
class WordDistance {
    unordered_map<string, vector<int>> map;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); i++) {
            map[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int last1 = -1, last2 = -1, minDist = 1e5;
        int j = 0;
        for (int i = 0; i < map[word1].size(); i++) {
            while (j < map[word2].size() && map[word2][j] < map[word1][i]) {
                minDist = min(minDist, map[word1][i] - map[word2][j]);
                j++;
            }
            if (j < map[word2].size()) minDist = min(minDist, map[word2][j] - map[word1][i]);
        }
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
// @lc code=end

