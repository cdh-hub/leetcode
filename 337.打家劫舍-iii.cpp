/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
private:
    pair<int, int> helper(TreeNode* root) {
        if (!root) return make_pair(0,0);
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        pair<int, int> result;
        result.first = l.second + r.second + root->val;
        result.second = max(l.first, l.second) + max(r.first, r.second);
        return result;
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> result = helper(root);
        return max(result.first, result.second);
    }
};
// @lc code=end

