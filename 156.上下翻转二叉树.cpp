/*
 * @lc app=leetcode.cn id=156 lang=cpp
 *
 * [156] 上下翻转二叉树
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
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left) return root;
        TreeNode* newRoot = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr;
        root->right = nullptr;
        return newRoot;
    }
};
// @lc code=end

