/*
 * @lc app=leetcode.cn id=250 lang=cpp
 *
 * [250] 统计同值子树
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
    int count = 0;
    bool dfs(TreeNode* root) {
        if (!root) return true;
        bool isLeftUni = dfs(root->left);
        bool isRightUni = dfs(root->right);
        if (!isLeftUni || !isRightUni) return false;
        if (!root->left && !root->right) {
            count++;
            return true;
        }
        if (!root->left && root->right->val == root->val) {
            count++;
            return true;
        }
        if (!root->right && root->left->val == root->val) {
            count++;
            return true;
        }
        if (root->left && root->right && root->left->val == root->val && root->right->val == root->val) {
            count++;
            return true;
        }
        return false;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
    }
};
// @lc code=end

