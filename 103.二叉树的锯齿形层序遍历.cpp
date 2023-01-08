/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        vector<vector<int>> res;
        if (root) nodeQueue.push(root);
        bool left2right = true;
        while (!nodeQueue.empty()) {
            vector<int> vals;
            vector<TreeNode*> nodes;
            while (!nodeQueue.empty()) {
                nodes.push_back(nodeQueue.front());
                vals.push_back(nodeQueue.front()->val);
                nodeQueue.pop();
            }
            for (auto iter = nodes.rbegin(); iter != nodes.rend(); iter++) {
                if (left2right) {
                    if ((*iter)->right) nodeQueue.push((*iter)->right);
                    if ((*iter)->left) nodeQueue.push((*iter)->left);
                }
                else {
                    if ((*iter)->left) nodeQueue.push((*iter)->left);
                    if ((*iter)->right) nodeQueue.push((*iter)->right);
                }
            }
            res.push_back(vals);
            left2right = !left2right;
        }
        return res;
    }
};
// @lc code=end

