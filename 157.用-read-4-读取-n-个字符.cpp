/*
 * @lc app=leetcode.cn id=157 lang=cpp
 *
 * [157] 用 Read4 读取 N 个字符
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
    int read(char *buf, int n) {
        int count = 0;
        char tmp[4];
        char* pos = buf;
        for (int i = 0; i < n / 4; i++) {
            int num = read4(tmp);
            count += num;
            for (int j = 0; j < num; j++) {
                *pos = tmp[j];
                pos++;
            }
            if (num < 4) break;
        }
        int num = read4(tmp);
        int tail = min(num, n % 4);
        count += tail;
        for (int i = 0; i < tail; i++) {
            *pos = tmp[i];
            pos++;
        }
        return count;
    }
};
// @lc code=end

