/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNode;
        queue<TreeNode*> q;
        if (root == nullptr) return rightNode;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int num = count;
            count = 0;
            for (int i = 1; i <= num; i++) {
                if (q.front()->left) q.push(q.front()->left), count++;
                if (q.front()->right) q.push(q.front()->right), count++;
                if (i == num) rightNode.push_back(q.front()->val);
                q.pop();
            }
        }
        return rightNode;
    }
};
// @lc code=end

