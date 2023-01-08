/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        TreeNode *pred = nullptr, *x = nullptr, *y = nullptr, *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                else {
                    predecessor->right = nullptr;
                    if (pred->val > root->val) {
                        if(x == nullptr) {
                            x = pred;
                        }
                        y = root;
                    }
                    pred = root;
                    root = root->right;
                }
            }
            else {
                if (pred != nullptr) {
                    if (pred->val > root->val) {
                        if(x == nullptr) {
                            x = pred;
                        }
                        y = root;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
};
// @lc code=end

