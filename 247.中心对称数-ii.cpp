/*
 * @lc app=leetcode.cn id=247 lang=cpp
 *
 * [247] 中心对称数 II
 */

// @lc code=start
class Solution {
private:
    string s = "";
    vector<string> res;
    int symmetry[3] = {'0', '1', '8'};
    unordered_map<char, char> symmetry2 {{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}}, 5};
    void helper(int i, int n) {
        if (i > (n - 1) / 2) {
            string s1 = "";
            for (int j = 0; j < n / 2; j++) {
                s1 = symmetry2[s[j]] + s1;
            }
            if (n == 1 || s[0] != '0') res.push_back(s+s1);
        }
        else if (i < n / 2){
            for (auto& [k,_]: symmetry2) {
                s += k;
                helper(i+1, n);
                s = s.substr(0, s.size()-1);
            }
        }
        else {
            for (int j = 0; j < 3; j++) {
                s += symmetry[j];
                helper(i+1, n);
                s = s.substr(0, s.size()-1);
            }
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        helper(0, n);
        return res;
    }
};
// @lc code=end

