/*
 * @lc app=leetcode.cn id=776 lang=cpp
 *
 * [776] 拆分二叉搜索树
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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if (!root) return {nullptr, nullptr};
        if (target < root->val) {
            vector<TreeNode*> l = splitBST(root->left, target);
            root->left = l[1];
            return {l[0], root};
        }
        else {
            vector<TreeNode*> r = splitBST(root->right, target);
            root->right = r[0];
            return {root, r[1]};
        }
    }
};
// @lc code=end

