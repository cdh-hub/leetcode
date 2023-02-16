/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] 每种字符至少取 K 个
 */

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        int a[3] = {-k, -k, -k};
        for (char ch: s) {
            a[ch-'a']++;
        }
        if (a[0] < 0 || a[1] < 0 || a[2] < 0) return -1;
        int ans = s.size(), right = s.size();
        for (int left = s.size()-1; left >= 0; left--) {
            a[s[left]-'a']--;
            while (a[s[left]-'a'] < 0) {
                right--;
                a[s[right]-'a']++;
            }
            ans = min(ans, (int)(s.size()-right+left));
        }
        return ans;
    }
};
// @lc code=end

