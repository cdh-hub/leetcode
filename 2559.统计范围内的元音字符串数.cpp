/*
 * @lc app=leetcode.cn id=2559 lang=cpp
 *
 * [2559] 统计范围内的元音字符串数
 */

// @lc code=start
class Solution {
private:
    bool isVowel(string& s) {
        char c[5] = {'a', 'e', 'i', 'o', 'u'};
        bool b1 = false, b2 = false;
        for (int i = 0; i < 5; i++) {
            if (s[0] == c[i]) b1 = true;
            if (s[s.size()-1] == c[i]) b2 = true;
        }
        return b1 && b2;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int preSum[words.size()+1];
        preSum[0] = 0;
        for (int i = 0; i < words.size(); i++) {
            preSum[i+1] = preSum[i] + (isVowel(words[i]) ? 1 : 0);
        }
        vector<int> ans;
        for (auto q: queries) {
            ans.push_back(preSum[q[1] + 1] - preSum[q[0]]);
        }
        return ans;
    }
};
// @lc code=end

