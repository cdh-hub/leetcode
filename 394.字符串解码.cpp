/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    int parseInt(string& s, int& index) {
        int n = 0;
        while (s[index] != '[') {
            n = n * 10 + s[index] - '0';
            index++;
        }
        return n;
    }
    string parse(string& s, int& index) {
        string ans;
        while (index < s.size() && s[index] != ']') {
            if (s[index] >= 'a' && s[index] <= 'z') {
                ans.push_back(s[index]);
                index++;
            }
            else {
                int n = parseInt(s, index);
                index++;
                string s2 = parse(s, index);
                index++;
                while (n--) ans += s2;
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int index = 0;
        return parse(s, index);
    }
};
// @lc code=end

