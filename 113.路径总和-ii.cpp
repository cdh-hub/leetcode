/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> paths;
    vector<int> currentPath;
    void helper(TreeNode* root, int targetSum) {
        currentPath.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
            paths.push_back(currentPath);
        }
        if (root->left) helper(root->left, targetSum - root->val);
        if (root->right) helper(root->right, targetSum - root->val);
        currentPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return paths;
        helper(root, targetSum);
        return paths;
    }
};
// @lc code=end

