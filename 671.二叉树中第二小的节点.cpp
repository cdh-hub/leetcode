/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    int minval;
    int secondmin = -1;
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->val == minval) {
            dfs(root->left);
            dfs(root->right);
        }
        else if (root->val < secondmin || secondmin == -1) secondmin = root->val;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        minval = root->val;
        dfs(root);
        return secondmin;
    }
};
// @lc code=end

