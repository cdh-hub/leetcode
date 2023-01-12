/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    unordered_map<string, int> mapping;
    vector<TreeNode*> nodes;
    string node2string(TreeNode* root) {
        if (!root) return "X";
        string l = node2string(root->left), r = node2string(root->right);
        string str = "(" + l + ")" + to_string(root->val) + "(" + r + ")";
        if (mapping[str] == 1) {
            nodes.push_back(root);
        }
        mapping[str]++;
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        node2string(root);
        return nodes;
    }
};
// @lc code=end

