/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool helper(TreeNode* root, long long min, long long max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root->left, LONG_LONG_MIN, root->val) && helper(root->right, root->val, LONG_LONG_MAX);
    }
};
// @lc code=end

