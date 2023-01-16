/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
class Solution {
private:
    bool isEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            for (int j = i+2; j < s1.size(); j+=2) {
                if (s1[i] == s2[j]) swap(s2[i], s2[j]);
            }
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
public:
    int numSpecialEquivGroups(vector<string>& words) {
        bool* record = new bool[words.size()];
        for (int i = 0; i < words.size(); i++) {
            record[i] = false;
        }
        int count = 0;
        for (int i = 0; i < words.size(); i++) {
            if (record[i]) continue;
            count++;
            record[i] = true;
            for (int j = i+1; j < words.size(); j++) {
                if (record[j]) continue;
                if (isEqual(words[i], words[j])) {
                    record[j] = true;
                }
            }
        }
        return count;
    }
};
// @lc code=end

