/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxSum = INT_MIN;
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftMax = helper(root->left);
        int rightMax = helper(root->right);
        int sum = root->val + max(0, leftMax) + max(0, rightMax);
        if (sum > maxSum) maxSum = sum;
        return root->val + max(max(leftMax, rightMax), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};
// @lc code=end

