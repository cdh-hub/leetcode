/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    int height;
    int findHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
    void tree2string(TreeNode* root, vector<vector<string>>& vec, int x, int y) {
        vec[x][y] = to_string(root->val);
        if (root->left) tree2string(root->left, vec, x + 1, y - (1 << (height - x - 2)));
        if (root->right) tree2string(root->right, vec, x + 1, y + (1 << (height - x - 2)));
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        height = findHeight(root);
        vector<vector<string>> vec(height, vector<string>((1 << height) - 1, ""));
        tree2string(root, vec, 0, (1 << (height - 1)) - 1);
        return vec;
    }
};
// @lc code=end

