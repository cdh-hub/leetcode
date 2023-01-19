/*
 * @lc app=leetcode.cn id=545 lang=cpp
 *
 * [545] 二叉树的边界
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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> vec;
        vec.push_back(root->val);
        if (!root->left && !root->right) return vec;
        TreeNode* p = root;
        if (p->left) {
            p = p->left;
            while (p->left || p->right) {
                vec.push_back(p->val);
                if (p->left) {
                    p = p->left;
                }
                else {
                    p = p->right;
                }
            }
        }
        p = root;
        while (p) {
            if (p->left) {
                TreeNode* q = p->left;
                while (q->right && q->right != p) {
                    q = q->right;
                }
                if (!q->right) {
                    q->right = p;
                    p = p->left;
                }
                else {
                    if (!q->left) vec.push_back(q->val);
                    q->right = nullptr;
                    p = p->right;
                }
            }
            else {
                if (!p->right) vec.push_back(p->val);
                p = p->right;
            }
        }
        p = root;
        int cnt = 0;
        if (p->right) {
            p = p->right;
            while (p->left || p->right) {
                cnt++;
                vec.push_back(p->val);
                if (p->right) {
                    p = p->right;
                }
                else {
                    p = p->left;
                }
            }
        }
        reverse(vec.end()-cnt, vec.end());
        return vec;
    }
};
// @lc code=end

