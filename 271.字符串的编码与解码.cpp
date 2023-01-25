/*
 * @lc app=leetcode.cn id=271 lang=cpp
 *
 * [271] 字符串的编码与解码
 */

// @lc code=start
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (string s: strs) {
            for (int i = 0; i < s.size(); i++) {
                res += s[i];
                if (s[i] == '\\') res += '\\';
            }
            res += "\\n";
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        string s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '\\') s1 += s[i];
            else if (s[i] == '\\' && s[i+1] == '\\') {
                s1 += '\\';
                i++;
            }
            else {
                strs.push_back(s1);
                i++;
                s1 = "";
            }
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end

