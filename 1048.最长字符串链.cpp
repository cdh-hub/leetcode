/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

// @lc code=start
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        int dp[n];
        int i = 0, j = 0;
        for (j = 0; j < n && words[j].size() == words[i].size(); j++) {
            dp[j] = 1;
        }
        int ans = 1;
        while (j < n) {
            int pre = i;
            i = j;
            while (j < n && words[j].size() == words[i].size()) {
                dp[j] = 1;
                if (words[i].size() == words[pre].size()+1)
                for (int k = pre; k < i; k++) {
                    if (check(words[k], words[j])) {
                        dp[j] = max(dp[j], dp[k]+1);
                    }
                }
                ans = max(ans, dp[j]);
                j++;
            }
        }
        return ans;
    }
private:
    bool check(string& a, string& b) {
        if (a.size()+1 == b.size()) {
            for (int i = 0, j = 0; i < a.size() && j < b.size(); i++, j++) {
                while (a[i] != b[j]) {
                    j++;
                    if (i + 1 < j) return false;
                }
            }
            return true;
        }
        return false;
    }
};
// @lc code=end

