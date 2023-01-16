/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int minDiffInBST(TreeNode* root) {
        int prev = -1e5, minDiff = INT_MAX;
        while (root) {
            if (root->left) {
                TreeNode* p = root->left;
                while (p->right && p->right != root) {
                    p = p->right;
                }
                if (!p->right) {
                    p->right = root;
                    root = root->left;
                }
                else {
                    p->right = nullptr;
                    int diff = root->val - prev;
                    minDiff = min(minDiff, diff);
                    prev = root->val;
                    root = root->right;
                }
            }
            else {
                int diff = root->val - prev;
                minDiff = min(minDiff, diff);
                prev = root->val;
                root = root->right;
            }
        }
        return minDiff;
    }
};
// @lc code=end

