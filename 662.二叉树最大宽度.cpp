/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
typedef unsigned long long ULL;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ULL>> q;
        int maxWidth = 1;
        q.push(make_pair(root, 1ULL));
        while (!q.empty()) {
            pair<TreeNode*, ULL> left = q.front(), right = q.back();
            if (right.second - left.second + 1 > maxWidth) maxWidth = right.second - left.second + 1; 
            int n = q.size();
            for (int i = 0; i < n; i++) {
                if (q.front().first->left) q.push(make_pair(q.front().first->left, q.front().second * 2));
                if (q.front().first->right) q.push(make_pair(q.front().first->right, q.front().second * 2 + 1));
                q.pop();
            }
        }
        return maxWidth;
    }
};
// @lc code=end

