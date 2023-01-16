/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */

// @lc code=start
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<long long> st;
        for (int i = 0; i < words.size(); i++) {
            long long a = 0;
            for (int j = 0; j < words[i].size(); j++) {
                a += 1LL << (words[i][j] - 'a' + 26 * (j & 1));
            }
            st.insert(a);
        }
        return st.size();
    }
};
// @lc code=end

