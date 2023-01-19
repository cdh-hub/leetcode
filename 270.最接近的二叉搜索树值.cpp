/*
 * @lc app=leetcode.cn id=270 lang=cpp
 *
 * [270] 最接近的二叉搜索树值
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
    int closestValue(TreeNode* root, double target) {
        double closest_dist = abs(root->val - target);
        int closest = root->val;
        while (root) {
            if (abs(root->val - target) < closest_dist) {
                closest_dist = abs(root->val - target);
                closest = root->val;
            }
            if (target > root->val) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        return closest;
    }
};
// @lc code=end

