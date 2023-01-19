/*
 * @lc app=leetcode.cn id=255 lang=cpp
 *
 * [255] 验证前序遍历序列二叉搜索树
 */

// @lc code=start
class Solution {
private:
    bool helper(vector<int>& preorder, int l, int r) {
        if (l > r) return true;
        int head = preorder[l];
        int pos = l + 1;
        while (pos <= r && preorder[pos] < head) pos++;
        int mid = pos;
        while (pos <= r && preorder[pos] > head) pos++;
        if (pos <= r) return false;
        else return helper(preorder, l+1, mid-1) && helper(preorder, mid, r);
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size()-1);
    }
};
// @lc code=end

