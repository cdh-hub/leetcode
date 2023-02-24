/*
 * @lc app=leetcode.cn id=1238 lang=cpp
 *
 * [1238] 循环码排列
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int v[1<<n];
        v[0] = 0;
        int pos = 0;
        for (int i = 0; i < n; i++) {
            for (int j = (1 << i)-1; j >= 0; j--) {
                v[(1<<(i+1))-j-1] = ((1 << i) | v[j]);
                if (((1 << i) | v[j]) == start) {
                    pos = (1<<(i+1))-j-1;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < (1<<n); i++) {
            ans.push_back(v[(pos+i)%(1<<n)]);
        }
        return ans;
    }
};
// @lc code=end

