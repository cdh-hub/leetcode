/*
 * @lc app=leetcode.cn id=249 lang=cpp
 *
 * [249] 移位字符串分组
 */

// @lc code=start
class Solution {
private:
    bool cmp(const string& s1, const string& s2) const {
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            if ((s1[i] - s2[i] + 26) % 26 != (s1[(i+1)%s1.size()] - s2[(i+1)%s1.size()] + 26) % 26) return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        for (auto s: strings) {
            bool tag = false;
            for (auto&& vec: res) {
                if (cmp(s, vec[0])) {
                    vec.push_back(s);
                    tag = true;
                    break;
                }
            }
            if (!tag) {
                res.push_back(vector<string>(1, s));
            }
        }
        return res;
    }
};
// @lc code=end

