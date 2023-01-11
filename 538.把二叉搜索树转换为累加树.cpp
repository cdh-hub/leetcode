/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {

        int sum = 0;
        TreeNode* p = root;
        while (p) {
            if (!p->right) {
                p->val += sum;
                sum = p->val;
                p = p->left;
            }
            else {
                TreeNode* q = p->right;
                while (q->left && q->left != p) {
                    q = q->left;
                }
                if (!q->left) {
                    q->left = p;
                    p = p->right;
                }
                else {
                    q->left = nullptr;
                    p->val += sum;
                    sum = p->val;
                    p = p->left;
                }
            }
        }
        return root;
    }
};
// @lc code=end

