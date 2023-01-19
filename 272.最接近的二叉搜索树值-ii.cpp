/*
 * @lc app=leetcode.cn id=272 lang=cpp
 *
 * [272] 最接近的二叉搜索树值 II
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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> inorder;
        while (root) {
            if (root->left) {
                TreeNode * p = root->left;
                while (p->right && p->right != root) {
                    p = p->right;
                }
                if (!p->right) {
                    p->right = root;
                    root = root->left;
                }
                else {
                    p->right = nullptr;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
            else {
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        double diff1 = abs(inorder[0] - target), diff2 = abs(inorder[k-1] - target);
        int i = 1;
        for (; i+k-1 < inorder.size(); i++) {
            if (abs(inorder[i+k-1] - target) > abs(inorder[i-1] - target)) break;
        }
        return vector<int>(inorder.begin()+(i-1), inorder.begin()+(i+k-1));
    }
};
// @lc code=end

