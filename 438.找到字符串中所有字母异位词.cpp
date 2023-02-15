/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
private:
    bool check(int count[]) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int count[26] = {0};
        for (char ch: p) count[ch-'a']++;
        vector<int> ans;
        if (s.size() >= p.size()) {
            for (int i = 0; i < p.size(); i++) {
                count[s[i]-'a']--;
            }
            if (check(count)) ans.push_back(0);
            for (int i = 1; i <= s.size() - p.size(); i++) {
                count[s[i-1]-'a']++;
                count[s[i+p.size()-1]-'a']--;
                if (check(count)) ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

