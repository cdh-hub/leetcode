/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
// private:
//     TreeNode* helper(vector<int>& nums, int begin, int end) {
//         if (begin > end) return nullptr;
//         int maxptr = -1;
//         int maxval = -1;
//         for (int i = begin; i <= end; i++) {
//             if (nums[i] > maxval) {
//                 maxval = nums[i];
//                 maxptr = i;
//             }
//         }
//         TreeNode* root = new TreeNode(maxval);
//         root->left = helper(nums, begin, maxptr-1);
//         root->right = helper(nums, maxptr+1, end);
//         return root;
//     }
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         return helper(nums, 0, nums.size()-1);
//     }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<TreeNode*> tree(n);
        for (int i = 0; i < n; i++) {
            tree[i] = new TreeNode(nums[i]);
            while (!stk.empty() && nums[i] > nums[stk.top()]) {
                tree[i]->left = tree[stk.top()];
                stk.pop();
            }
            if (!stk.empty()) {
                tree[stk.top()]->right = tree[i];
            }
            stk.push(i);
        }
        while (stk.size() > 1) stk.pop();
        return tree[stk.top()];
    }
};
// @lc code=end

