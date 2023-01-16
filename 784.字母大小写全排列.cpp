/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
private:
    vector<string> ss;
    string s;
    void fun(int index) {
        while (index < s.size() && !(s[index] >= 'a' && s[index] <= 'z' || s[index] >= 'A' && s[index] <= 'Z')) {
            index++;
        }
        if (index == s.size()) {
            ss.push_back(s);
        }
        else {
            if (s[index] >= 'a' && s[index] <= 'z') {
                fun(index+1);
                s[index] += 'A' - 'a';
                fun(index+1);
                s[index] -= 'A' - 'a';
            }
            else {
                fun(index+1);
                s[index] += 'a' - 'A';
                fun(index+1);
                s[index] -= 'a' - 'A';
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        this->s = s;
        fun(0);
        return ss;
    }
};
// @lc code=end

