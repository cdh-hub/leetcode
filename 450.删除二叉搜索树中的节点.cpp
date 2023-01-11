/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *p = root, *prev = nullptr;
        while (p && p->val != key) {
            prev = p;
            if (p->val > key) {
                p = p->left;
            }
            else {
                p = p->right;
            }
        }
        if (!p) return root;
        if (!p->left) {
            if (!prev) {
                TreeNode* tmp = p->right;
                delete(p);
                return tmp;
            }
            if (prev->left == p) {
                prev->left = p->right;
                delete(p);
            }
            else {
                prev->right = p->right;
                delete(p);
            }
            return root;
        }
        if (!p->right) {
            if (!prev) {
                TreeNode* tmp = p->left;
                delete p;
                return tmp;
            }
            if (prev->left == p) {
                prev->left = p->left;
                delete p;
            }
            else {
                prev->right = p->left;
                delete p;
            }
            return root;
        }
        TreeNode* q = p->left;
        while (q->right) {
            q = q->right;
        }
        TreeNode* tmp = p->right;
        q->right = tmp->left;
        p->val = tmp->val;
        p->right = tmp->right;
        delete tmp;
        return root;
    }
};
// @lc code=end

