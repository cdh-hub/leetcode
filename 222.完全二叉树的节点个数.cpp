/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int nodeHeight(TreeNode* root) {
        int count = 0;
        while (root) {
            count++;
            root = root->left;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = nodeHeight(root->left);
        int rightHeight = nodeHeight(root->right);
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) + countNodes(root->right);
        }
        else {
            return countNodes(root->left) + (1 << rightHeight);
        }
    }
};
// @lc code=end

