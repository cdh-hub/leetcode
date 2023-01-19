/*
 * @lc app=leetcode.cn id=549 lang=cpp
 *
 * [549] 二叉树中最长的连续序列
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
typedef struct ReturnType{
    int leftUp;
    int leftDown;
    int rightUp;
    int rightDown;
    int longest;
} rt;
class Solution {
private:
    rt dfs(TreeNode* root) {
        rt rtl, rtr;
        if (root->left) rtl = dfs(root->left);
        if (root->right) rtr = dfs(root->right);
        rt res;
        if (!root->left) {
            res.leftDown = 1;
            res.leftUp = 1;
        }
        else if (root->val + 1 == root->left->val) {
            res.leftUp = max(rtl.leftUp, rtl.rightUp) + 1;
            res.leftDown = 1;
        }
        else if (root->val - 1 == root->left->val) {
            res.leftDown = max(rtl.leftDown, rtl.rightDown) + 1;
            res.leftUp = 1;
        }
        else {
            res.leftDown = 1;
            res.leftUp = 1;
        }
        if (!root->right) {
            res.rightDown = 1;
            res.rightUp = 1;
        }
        else if (root->val + 1 == root->right->val) {
            res.rightUp = max(rtr.leftUp, rtr.rightUp) + 1;
            res.rightDown = 1;
        }
        else if (root->val - 1 == root->right->val) {
            res.rightDown = max(rtr.leftDown, rtr.rightDown) + 1;
            res.rightUp = 1;
        }
        else {
            res.rightDown = 1;
            res.rightUp = 1;
        }
        if (!root->left && !root->right) {
            res.longest = 1;
        }
        else if (!root->left) {
            res.longest = max(max(res.rightDown, res.rightUp), rtr.longest);
        }
        else if (!root->right) {
            res.longest = max(max(res.leftDown, res.leftUp), rtl.longest);
        }
        else {
            res.longest = max(max(res.leftDown + res.rightUp - 1, res.leftUp + res.rightDown - 1), max(rtl.longest, rtr.longest));
        }
        return res;
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        return dfs(root).longest;
    }
};
// @lc code=end

