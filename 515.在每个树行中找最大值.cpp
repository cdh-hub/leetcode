/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> maxNums;
        if (!root) return maxNums;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            int maxNum = INT_MIN;
            TreeNode* curNode;
            while (q.front()) {
                curNode = q.front();
                q.pop();
                if (curNode->val > maxNum) maxNum = curNode->val;
                if (curNode->left) q.push(curNode->left);
                if (curNode->right) q.push(curNode->right);
            }
            q.pop();
            if (!q.empty()) q.push(nullptr);
            maxNums.emplace_back(maxNum);
        }
        return maxNums;
    }
};
// @lc code=end

