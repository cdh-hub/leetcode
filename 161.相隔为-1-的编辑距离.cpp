/*
 * @lc app=leetcode.cn id=161 lang=cpp
 *
 * [161] 相隔为 1 的编辑距离
 */

// @lc code=start
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if (n1 - n2 > 1 || n1 - n2 < -1) return false;
        if (n1 == n2) {
            int cnt = 0;
            for (int i = 0; i < n1; i++) {
                if (s[i] != t[i]) cnt++;
                if (cnt > 1) return false;
            }
            return cnt == 1;
        }
        else {
            if (n1 > n2) {
                swap(s, t);
                swap(n1, n2);
            }
            bool tag = false;
            for (int i = 0; i < n2; i++) {
                if (!tag) {
                    if (s[i] == t[i]) continue;
                    tag = true;
                }
                else {
                    if (s[i-1] != t[i]) return false;
                }
            }
            return true;
        }
    }
};
// @lc code=end

