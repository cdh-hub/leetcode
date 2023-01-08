/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool helper(TreeNode* root, int & height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }
        else {
            bool isLeftBalanced, isRightBalanced;
            int heightLeft, heightRight;
            isLeftBalanced = helper(root->left, heightLeft);
            if (!isLeftBalanced) return false;
            isRightBalanced = helper(root->right, heightRight);
            height = max(heightLeft, heightRight) + 1;
            return isLeftBalanced && isRightBalanced && heightLeft - heightRight <= 1 && heightRight - heightLeft <= 1;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        int height;
        return helper(root, height);
    }
};
// @lc code=end

