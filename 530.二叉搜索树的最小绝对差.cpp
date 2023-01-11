/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int lastNum = -1;
        TreeNode* p = root;
        while (p) {
            if (!p->left) {
                int diff = p->val - lastNum;
                if (lastNum != -1 && diff < minDiff) minDiff = diff;
                lastNum = p->val;
                p = p->right;
            }
            else {
                TreeNode* q = p->left;
                while (q->right && q->right != p) {
                    q = q->right;
                }
                if (!q->right) {
                    q->right = p;
                    p = p->left;
                }
                else {
                    q->right = nullptr;
                    int diff = p->val - lastNum;
                    if (lastNum != -1 && diff < minDiff) minDiff = diff;
                    lastNum = p->val;
                    p = p->right;
                }
            }
        }
        return minDiff;
    }
};
// @lc code=end

