/*
 * @lc app=leetcode.cn id=158 lang=cpp
 *
 * [158] 用 Read4 读取 N 个字符 II
 */

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buf4[4];
    int index = 0;
    int valid = 0;
    int read(char *buf, int n) {
        int cnt = 0;
        while (index < valid && n) {
            *buf = buf4[index];
            index++;
            buf++;
            cnt++;
            n--;
        }
        while (n > 0) {
            valid = read4(buf4);
            for (index = 0; index < min(n, valid); index++) {
                *buf = buf4[index];
                buf++;
                cnt++;
            }
            if (valid < 4) break;
            n -= 4;
        }
        return cnt;
    }
};
// @lc code=end

