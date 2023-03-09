/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        for (char ch: blocks) if (ch == 'W') cnt++;
        int l = 0, r = cnt;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (check(blocks, mid, k)) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
private:
    bool check(string& blocks, int m, int k) {
        int cnt = 0;
        for (int i = 0; i < k; i++) if (blocks[i] == 'B') cnt++;
        if (cnt + m >= k) return true;
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'B') cnt++;
            if (blocks[i-k] == 'B') cnt--;
            if (cnt + m >= k) return true;
        }
        return false;
    }
};
// @lc code=end

