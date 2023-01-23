/*
 * @lc app=leetcode.cn id=246 lang=cpp
 *
 * [246] 中心对称数
 */

// @lc code=start
class Solution {
private:
    char symmetry(char a) {
        switch (a) {
            case '0':
                return '0';
            case '1':
                return '1';
            case '6':
                return '9';
            case '8':
                return '8';
            case '9':
                return '6';        
            default:
                return '\0';
        }
    }
public:
    bool isStrobogrammatic(string num) {
        for (int i = 0; i <= num.size() / 2; i++) {
            if (symmetry(num[i]) != num[num.size()-i-1])
            return false;
        }
        return true;
    }
};
// @lc code=end

