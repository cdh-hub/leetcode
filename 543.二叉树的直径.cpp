/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int, int> helper(TreeNode* root) {
        if (!root) return make_pair(-1, -1);
        if (!root->left && !root->right) return make_pair(0, 0);
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        int height = max(l.first, r.first) + 1;
        int pathLen =  max(max(l.second, r.second), l.first + r.first + 2);
        return make_pair(height, pathLen);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};
// @lc code=end

