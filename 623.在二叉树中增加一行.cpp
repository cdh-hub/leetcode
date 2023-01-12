/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        queue<TreeNode*> q;
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        q.push(root);
        int count = 1, countDepth = 1;
        while (!q.empty() && countDepth < depth) {
            int n = count;
            count = 0;
            if (countDepth < depth - 1)
                for (int i = 0; i < n; i++) {
                    if (q.front()->left) q.push(q.front()->left), count++; 
                    if (q.front()->right) q.push(q.front()->right), count++;
                    q.pop();
                }
            else for (int i = 0; i < n; i++) {
                TreeNode *l = new TreeNode(val), *r = new TreeNode(val);
                l->left = q.front()->left, r->right = q.front()->right;
                q.front()->left = l, q.front()->right = r;
                q.pop();
            }
            countDepth++;
        }
        return root;
    }
};
// @lc code=end

