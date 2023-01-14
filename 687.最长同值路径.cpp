/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestPath = 0;
    int longestPathHelper(TreeNode* root) {
        if (!root) return 0;
        int left = longestPathHelper(root->left), right = longestPathHelper(root->right);
        int leftpath = 0, rightpath = 0;
        if (root->left && root->left->val == root->val) leftpath += left + 1;
        if (root->right && root->right->val == root->val) rightpath += right + 1;
        if (leftpath + rightpath > longestPath) longestPath = leftpath + rightpath;
        return max(leftpath, rightpath); 
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        longestPathHelper(root);
        return longestPath;
    }
};
// @lc code=end

