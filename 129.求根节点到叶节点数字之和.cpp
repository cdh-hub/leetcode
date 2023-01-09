/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sum = 0;
    int currentNum = 0;
    void dfs(TreeNode* root) {
        currentNum = currentNum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr) sum += currentNum;
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        currentNum = currentNum/10;
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
// @lc code=end

