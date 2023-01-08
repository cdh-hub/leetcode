/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> nodes;
            vector<int> vals;
            while (!q.empty()) {
                nodes.push_back(q.front());
                vals.push_back(q.front()->val);
                q.pop();
            }
            res.push_back(vals);
            for(auto iter = nodes.begin(); iter != nodes.end(); iter++) {
                if ((*iter)->left != nullptr) q.push((*iter)->left);
                if ((*iter)->right != nullptr) q.push((*iter)->right);
            }
        }
        return res;
    }
};
// @lc code=end

