/*
 * @lc app=leetcode.cn id=1487 lang=cpp
 *
 * [1487] 保证文件名唯一
 */

// @lc code=start
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> mp;
        vector<string> ans(names.begin(), names.end());
        for (string &s: ans) {
            if (!mp.count(s)) {
                mp[s] = 1;
            }
            else {
                int cnt = mp[s];
                while (mp.count(s+"("+to_string(cnt)+")")) {
                    cnt++;
                }
                mp[s] = cnt+1;
                s = s+"("+to_string(cnt)+")";
                mp[s] = 1;
            }
        }
        return ans;
    }
};
// @lc code=end

