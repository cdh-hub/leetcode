/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int count = 0;
        stk.push(root);
        while (!stk.empty()) {
            while (stk.top()->left) {
                stk.push(stk.top()->left);
            }
            while (stk.top()->right == nullptr) {
                count++;
                if (count == k) return stk.top()->val;
                stk.pop();
            }
            count++;
            if (count == k) return stk.top()->val;
            TreeNode* tmp = stk.top();
            stk.pop();
            stk.push(tmp->right);
        }
        return 0;
    }
};
// @lc code=end

