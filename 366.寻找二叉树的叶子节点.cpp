/*
 * @lc app=leetcode.cn id=366 lang=cpp
 *
 * [366] 寻找二叉树的叶子节点
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
    vector<vector<int>> vec;
    int dfs(TreeNode* root) {
        if (!root) return -1;
        int l = dfs(root->left), r = dfs(root->right);
        int height = max(l, r) + 1;
        if (vec.size() > height) vec[height].push_back(root->val);
        else vec.push_back(vector<int>(1, root->val));
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return vec;
    }
};
// @lc code=end

