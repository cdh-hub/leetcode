/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> nodes;
            vector<int> vals;
            while (!q.empty()) {
                nodes.push_back(q.front());
                vals.push_back(q.front()->val);
                q.pop();
            }
            result.push_back(vals);
            for (auto i = nodes.begin(); i != nodes.end(); i++) {
                if ((*i)->left) q.push((*i)->left);
                if ((*i)->right) q.push((*i)->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

