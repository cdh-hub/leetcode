/*
 * @lc app=leetcode.cn id=1096 lang=cpp
 *
 * [1096] 花括号展开 II
 */

// @lc code=start
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int pos = 0;
        unordered_set<string> ans = parse(expression, pos);
        vector<string> ans_vec(ans.begin(), ans.end());
        sort(ans_vec.begin(), ans_vec.end());
        return ans_vec;
    }
    unordered_set<string> parse(string& s, int& pos) {
        unordered_set<string> st;
        st.insert("");
        while (pos < s.size() && s[pos] != ',' && s[pos] != '}') {
            if (s[pos] == '{') {
                unordered_set<string> st1;
                do {
                    pos++;
                    unordered_set<string> st2 = parse(s, pos);
                    for(string str2: st2) st1.insert(str2);
                } while (s[pos] != '}');
                unordered_set<string> st_new;
                for (string str: st) {
                    for (string str1: st1) {
                        st_new.insert(str+str1);
                    }
                }
                st = st_new;
            }
            else {
                unordered_set<string> st_new;
                for (string str: st) {
                    st_new.insert(str + s[pos]);
                }
                st = st_new;
            }
            pos++;
        }
        return st;
    }
};
// @lc code=end

