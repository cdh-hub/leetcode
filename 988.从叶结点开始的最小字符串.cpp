/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
    string mins = string(1, 'z' + 1);
    void dfs(TreeNode* root, string& s) {
        if (!root) return;
        s.insert(0, 1, 'a' + root->val);
        if (!root->left && !root->right) mins = min(mins, s);
        dfs(root->left, s);
        dfs(root->right, s); 
        s.erase(s.begin());
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string s;
        dfs(root, s);
        return mins;
    }
};
// @lc code=end

