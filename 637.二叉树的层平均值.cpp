/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        vector<double> avgs;
        while (!q.empty()) {
            int n = count;
            count = 0;
            double avg = 0;
            for (int i = 0; i < n; i++) {
                avg += q.front()->val;
                if (q.front()->left) {
                    q.push(q.front()->left);
                    count++;
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                    count++;
                }
                q.pop();
            }
            avg /= n;
            avgs.emplace_back(avg);
        }
        return avgs;
    }
};
// @lc code=end

