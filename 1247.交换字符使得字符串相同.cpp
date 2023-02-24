/*
 * @lc app=leetcode.cn id=1247 lang=cpp
 *
 * [1247] 交换字符使得字符串相同
 */

// @lc code=start
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int a = 0, b = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            if (s1[i] == 'x') a++;
            else b++;
        }
        if ((a+b)&1) return -1;
        return (a+1)/2 + (b+1)/2; 
    }
};
// @lc code=end

