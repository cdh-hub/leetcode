/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
private:
    map<int, int> mapping;
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        if (mapping.count(n) == 1) return mapping[n];
        int count = 0;
        for (int i = 1; i <= n; i++) {
            count += numTrees(i-1) * numTrees(n-i);
        }
        mapping[n] = count;
        return count;
    }
};
// @lc code=end

