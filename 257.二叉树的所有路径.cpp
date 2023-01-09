/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> paths;
    void dfs(TreeNode* root, string& path) {
        if (root == nullptr) return;
        path += "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        }
        if (root->left) dfs(root->left, path);
        if (root->right) dfs(root->right, path);
        path.erase(path.end()-to_string(root->val).size()-2, path.end());
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
        return paths;
    }
};
// @lc code=end

