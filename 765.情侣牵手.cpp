/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
private:
    int* tree;
    int n;
    int find(int x) {
        if (x == tree[x]) return x;
        return tree[x] = find(tree[x]);
    }
    void un(int x, int y) {
        if (tree[find(x)] != find(y)) n--;
        tree[find(x)] = find(y);
    }
public:
    int minSwapsCouples(vector<int>& row) {
        n = row.size() >> 1;
        tree = new int[n];
        for (int i = 0; i < n; i++) {
            tree[i] = i;
        }
        for (int i = 0; i < row.size(); i += 2) {
            un(row[i]>>1, row[i+1]>>1);
        }
        return (row.size() >> 1) - n;
    }
};
// @lc code=end

