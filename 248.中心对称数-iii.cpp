/*
 * @lc app=leetcode.cn id=248 lang=cpp
 *
 * [248] 中心对称数 III
 */

// @lc code=start
class Solution {
private:
    int count = 0;
    void dfs(string& s, string& low, string& high) {
        int n = s.size(), l = low.size(), h = high.size();
        if (n > l && n < h) {
            if (s[0] != '0' || n == 1) count++;
        }
        else if (n == h && n == l) {
            if (s >= low && s <= high && (s[0] != '0' || n == 1)) count++;
        }
        else if (n == h && s <= high) {
            if (s[0] != '0' || n == 1) count++;
        }
        else if (n == l && s >= low) {
            if (s[0] != '0' || n == 1) count++;
        }
        if (n < h && n % 2 == 0) {
            string tmp = s;
            s = s.substr(0, n/2) + "0" + s.substr(n/2, n/2); dfs(s, low, high); s = tmp;
            s = s.substr(0, n/2) + "1" + s.substr(n/2, n/2); dfs(s, low, high); s = tmp;
            s = s.substr(0, n/2) + "8" + s.substr(n/2, n/2); dfs(s, low, high); s = tmp;
            s = "0" + s + "0"; dfs(s, low, high); s = tmp;
            s = "1" + s + "1"; dfs(s, low, high); s = tmp;
            s = "6" + s + "9"; dfs(s, low, high); s = tmp;
            s = "8" + s + "8"; dfs(s, low, high); s = tmp;
            s = "9" + s + "6"; dfs(s, low, high); s = tmp;
        }
    }
public:
    int strobogrammaticInRange(string low, string high) {
        string s = "";
        dfs(s, low, high);
        return count;
    }
};
// @lc code=end

