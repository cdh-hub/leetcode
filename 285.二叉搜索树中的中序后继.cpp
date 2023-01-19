/*
 * @lc app=leetcode.cn id=285 lang=cpp
 *
 * [285] 二叉搜索树中的中序后继
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            TreeNode* q = p->right;
            while (q->left) {
                q = q->left;
            }
            return q;
        }
        else {
            TreeNode* succ = nullptr;
            while (root != p) {
                if (root->val < p->val) {
                    root = root->right;
                }
                else {
                    succ = root;
                    root = root->left;
                }
            }
            return succ;
        }
    }
};
// @lc code=end

