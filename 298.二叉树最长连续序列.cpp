/*
 * @lc app=leetcode.cn id=298 lang=cpp
 *
 * [298] 二叉树最长连续序列
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
    int maxlen = 0;
    void dfs(TreeNode* root, int len) {
        maxlen = max(maxlen, len);
        if (root->left) {
            dfs(root->left, root->left->val == root->val + 1 ? (len + 1) : 1);
        }
        if (root->right) {
            dfs(root->right, root->right->val == root->val + 1 ? (len + 1) : 1);
        }
    }
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root, 1);
        return maxlen;
    }
};
// @lc code=end

