/*
 * @lc app=leetcode.cn id=1012 lang=cpp
 *
 * [1012] 至少有 1 位重复的数字
 */

// @lc code=start
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int slen = s.size();
        if (slen == 1) return 0;
        int ans = 9, pre = 9;
        for (int i = 1; i < slen-1; i++) ans += (pre *= (10-i));
        int record[10] = {0};
        int i = 0;
        for (; i < slen; i++) {
            int a = s[i]-'0', b = 0;
            for (int j = 0; j < 10; j++) if (record[j]) {
                if (j < s[i]-'0') a--; 
                b++;
            }
            if (i == 0) a--;
            for (int j = i+1; j < slen; j++) a *= 10-b-(j-i);
            ans += a;
            if (record[s[i]-'0'] == 1) break;
            record[s[i]-'0'] = 1;
        }
        if (i == slen) ans += 1;
        return n - ans;
    }
};
// @lc code=end

